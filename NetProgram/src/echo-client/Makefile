CC=gcc
BUILD_PATH=../lib
TARGET=echo-client

all: echo-client.c
	${CC} -o ${TARGET} echo-client.c ${BUILD_PATH}/arron.a

clean:
	rm -fr *.o && rm -fr ${TARGET}
