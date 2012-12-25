#!/bin/sh

TOPDIR=../..

g++  -I$TOPDIR/include  -I$TOPDIR/include/ullib -Werror -g -finline-functions  -Winline -pipe -DVERSION="\"0.0.1.1\"" -fPIC  -c bicat.cpp -o bicat.o

g++ -o bicat bicat.o -L$TOPDIR/lib -L./ullib/lib -Wl,--whole-archive -lmapred -Wl,--no-whole-archive -lullib -lpthread 

