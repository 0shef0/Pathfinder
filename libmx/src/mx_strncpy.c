#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    while (*src) {
        *dst = *src;
        dst++;
        src++;
        i++;
    }
    dst -= i;
    i = len;
    while(dst[i]){
        *(dst + i) = '\0';
        i++;
    }
    return dst;
}
