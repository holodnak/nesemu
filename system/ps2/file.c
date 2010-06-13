/***************************************************************************
 *   Copyright (C) 2006-2009 by Dead_Body   *
 *   jamesholodnak@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <tamtypes.h>
#include <sys/fcntl.h>
#include <fileXio_rpc.h>
#include "system/file.h"

#define FILE_MC		0x01
#define FILE_HDD		0x02
#define FILE_GZ		0x40
#define FILE_TEMP		0x80

#define CHUNK 0x8000

/*
the method used for reading gzipped files from the hard drive
is very bad.  currently, it decompresses the rom to a temporary
file in the root of the roms partition, then deletes it when
the file is closed.

*/

typedef struct file_s {
	int fd;
	FILE *fp;
	u32 flags;
	long length;
	char name[512];
} file_t;

static file_t files[16];
static int numfiles = 0;

static void make_temp_fn(char *fn)
{
	int i,n;

	for(i=0;i<8;i++) {
		n = rand() % (26 * 2);
		if(n < 26)
			fn[i] = n + 'A';
		else
			fn[i] = n + 'a' - 26;
	}
	memcpy(&fn[i],".tmp\0",5);
}

void file_init()
{
	memset(files,0,sizeof(file_t) * 16);
	numfiles = 0;
}

void file_kill()
{
}

int file_open(char *filename,char *oldmode)
{
	int hdd = 0;
	int fd = 0;
	char ch,mode[8] = "\0\0\0\0\0\0\0\0",*p = mode;

	//detect if the file is located on the hard drive
	if(strncmp(filename,"pfs0:",5) == 0)
		hdd = 1;

	while((ch = *oldmode++)) {
		if(ch == 'u') {
			continue;
		}
		if(ch == 'z') {
			continue;
		}
		*p++ = ch;
	}
	printf("opening '%s' in mode '%s'\n",filename,mode);
	for(fd=0;fd<16;fd++) {
		if(files[fd].flags == 0) {
			if(hdd) {
				int flags;
				char *m;

				for(flags=0,m=mode;*m;m++) {
					switch(*m) {
						case 'r': flags = O_RDONLY; break;
						case 'w': flags = O_WRONLY; break;
						case 'a': flags = O_RDWR; break;
					}
				}
				if((files[fd].fd = fileXioOpen(filename,flags,0)) >= 0) {
					files[fd].flags = FILE_HDD;
					file_seek(fd,0,SEEK_END);
					files[fd].length = file_tell(fd);
					file_seek(fd,0,SEEK_SET);
					return(fd);
				}
				else {
					printf("error opening file '%s'\n",filename);
					return(-1);
				}
			}
			else {
				if((files[fd].fp = fopen(filename,mode))) {
					printf("opening file with fopen'%s'\n",filename);
					files[fd].fd = 0;
					files[fd].flags = FILE_MC;
					return(fd);
				}
				else {
					printf("error opening file '%s'\n",filename);
					return(-1);
				}
			}
		}
	}
	return(-1);
}

void file_close(int fd)
{
	if(files[fd].flags & FILE_HDD)
		fileXioClose(files[fd].fd);
	else
		fclose(files[fd].fp);
	if(files[fd].flags & FILE_TEMP) {
		printf("removing temp file '%s'\n",files[fd].name);
		fileXioRemove(files[fd].name);
	}
	memset(&files[fd],0,sizeof(file_t));
}

int file_gets(int fd,char *buf,int maxlen)
{
	u8 ch;

	*buf = 0;
	for(;;) {
		int read = file_read(fd,&ch,1);

		if(read != 1 || ch == '\n' || ch == 0) {
			*buf = 0;
			return(strlen(buf));
		}
		*buf++ = ch;
	}
	return(0);
}

int file_read(int fd,void *buf,int len)
{
	if(files[fd].flags & FILE_HDD)
		return(fileXioRead(files[fd].fd,buf,len));
	return(fread(buf,1,len,files[fd].fp));
}

int file_write(int fd,void *buf,int len)
{
	if(files[fd].flags & FILE_HDD)
		return(fileXioWrite(files[fd].fd,buf,len));
	return(fwrite(buf,1,len,files[fd].fp));
}

long file_seek(int fd,long pos,int whence)
{
	if(files[fd].flags & FILE_HDD)
		return(fileXioLseek(files[fd].fd,pos,whence));
	return(fseek(files[fd].fp,pos,whence));
}

long file_tell(int fd)
{
	return(file_seek(fd,0,SEEK_CUR));
}

int file_eof(int fd)
{
	if(files[fd].flags & FILE_HDD) {
		if(file_tell(fd) >= files[fd].length)
			return(0);
		return(1);
	}
	return(feof(files[fd].fp));
}
