#!/bin/sh

./wla-6502.exe -o hle_fds.s hle_fds.o
./wlalink.exe -b linkfile hle_fds.bin
#gzip hle_fds.bin
#cp -u hle_fds.bin.gz ../../hle_fds.bin.gz
cp hle_fds.bin ../../
