SRC=src
SRC_EXE=${SRC}/simple_uptime
DES_EXE=simple_uptime
INSTALL_EXE=/usr/bin/simple_uptime

all: build
	@mv -v ${SRC_EXE} ${DES_EXE}

build:
	@cd ${SRC}; \
		make -f Makefile

install:
	install -Dm 775 ${DES_EXE} ${INSTALL_EXE}

uninstall:
	@rm -vf ${INSTALL_EXE}

clean:
	@rm -v ${DES_EXE}
	@find -type f -iname '*.o' -exec rm -v {} \;
