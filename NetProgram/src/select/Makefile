CC=gcc
BUILD_PATH=../lib
SERVER_PATH=./select-echo-server
CLIENT_PATH=./select-echo-client

server:
	@for ser in $$(ls ${SERVER_PATH}/echo-server*.c);\
	do\
		Filename=$${ser##*/};\
		${CC} -o $${Filename%.*} $${ser} ${BUILD_PATH}/arron.a;\
	done
client:
	@for ser in $$(ls ${SERVER_PATH}/echo-server*.c);\
	do\
		Filename=$${ser##*/};\
		${CC} -o $${Filename%.*} $${ser} ${BUILD_PATH}/arron.a;\
	done
build:
	cd ${BUILD_PATH} && find *.c | xargs gcc -c
	cd ${BUILD_PATH} && ar -r arron.a *.o

clean:
	rm -fr *.o && rm -fr a.out && cd lib && rm -fr *.o && rm -fr *.a
