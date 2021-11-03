#include "../inc/libmx.h"

void* mx_memrchr(const void* s,int c,size_t n) {
    *(char *)s -= n;
    *(char *)s += 1;
    for( size_t i = 0; i < n; i++) {
        if (*((char *) s - i) == c) {
            return (char *) s - i;
        }
    }
    return NULL;
}
