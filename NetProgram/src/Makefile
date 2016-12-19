CC=gcc
BUILD_PATH=./lib
build:
	cd ${BUILD_PATH} && find *.c | xargs gcc -c
	cd ${BUILD_PATH} && ar -r arron.a *.o
clean:
	rm -fr *.o && rm -fr *.a

