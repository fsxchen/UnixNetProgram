CC=gcc
BUILD_PATH=./lib
build:
	cd ${BUILD_PATH} && find *.c | xargs gcc -c
	cd ${BUILD_PATH} && ar -r arron.a *.o
clean:
	rm -fr ${BUILD_PATH}/*.o && rm -fr ${BUILD_PATH}/*.a

