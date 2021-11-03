#include "../inc/libmx.h"

void* mx_memset(void* b, int c, size_t len) {
    if (b) {
        char *tmp = (char *)b;
        while (len--) {
            *tmp++ = c;
        }
    }
    return b;
}
