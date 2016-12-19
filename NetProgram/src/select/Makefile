CC=gcc
BUILD_PATH=../lib
all: echo-server.c
	${CC} -o echo-server echo-server.c ${BUILD_PATH}/arron.a
build:
	cd ${BUILD_PATH} && find *.c | xargs gcc -c
	cd ${BUILD_PATH} && ar -r arron.a *.o

clean:
	rm -fr *.o && rm -fr a.out && cd lib && rm -fr *.o && rm -fr *.a
