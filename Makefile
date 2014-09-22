CC=gcc
CFLAGS=-Wall -O3 -march=native
INSTALL=/usr/bin/install

all:
	${CC} ${CFLAGS} -o simple_uptime simple_uptime.c
