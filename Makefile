# shortcut makefile
#
# to make specific targets for a target, try:
#   make linux TARGETS="clean all gdb"

win32:
	$(MAKE) -f Makefile.win32 $(TARGETS)
linux:
	$(MAKE) -f Makefile.linux $(TARGETS)
osx:
	$(MAKE) -f Makefile.osx $(TARGETS)
ps2:
	$(MAKE) -f Makefile.ps2 $(TARGETS)
wii:
	$(MAKE) -f Makefile.wii $(TARGETS)
all:
	echo specify a target.\
