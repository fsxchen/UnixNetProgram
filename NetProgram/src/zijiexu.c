#include <stdio.h>

#ifndef CPU_VENDOR_OS
#define  CPU_VENDOR_OS "Mac 10.11.04"
#endif

int main(int argc, char **argv) {
    union {
        short s;
        char c[sizeof(short)];
    } un;

    un.s = 0x0102;

    printf("%s: ", CPU_VENDOR_OS);
    if (sizeof(short) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2) {
            printf("big-endian\n");
        } else if (un.c[0] == 2 && un.c[1] == 1) {
            printf("little-endian\n");
        } else {
            printf("unknown");
        }
    } else {
        printf("sizeof(short) = %lu\n", sizeof(short));
    }
    return 0;
}
