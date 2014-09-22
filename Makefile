SRC=src
SRC_EXE=${SRC}/simple_uptime
DES_EXE=simple_uptime

all: build
	@mv -v ${SRC_EXE} ${DES_EXE}

build:
	@cd ${SRC}; \
		make -f Makefile

clean:
	@rm -v ${DES_EXE}
	@find -type f -iname '*.o' -exec rm -v {} \;
