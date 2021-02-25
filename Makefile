.PHONY: build run test clean

MAKEFLAGS = --no-print-directory
BUILDDIR = ./build/
SRCDIR = ./src/
SERVERPID = server.PID
COMPILED = Main
TESTCOMPILED = MainTest

build:
	@echo "Building DNS server"
	@mkdir -p ${BUILDDIR}
	@g++ -std=c++17 -o ${BUILDDIR}${COMPILED} ${SRCDIR}main.cpp

run:
	@echo "Starting DNS server"
	@${BUILDDIR}/${COMPILED}

test:
	@$(MAKE) COMPILED=${TESTCOMPILED} build
	@$(MAKE) COMPILED=${TESTCOMPILED} run & echo "$$!" > ${BUILDDIR}${SERVERPID}
	@dig @127.0.0.1 example.com -p 8080
	@kill `cat ${BUILDDIR}${SERVERPID}` && rm ${BUILDDIR}${SERVERPID}
	@rm ${BUILDDIR}${TESTCOMPILED}

clean:
	@echo "Clearing out build directory"
	@rm -rf ${BUILDDIR}
