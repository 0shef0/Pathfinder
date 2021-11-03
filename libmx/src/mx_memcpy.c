#include "../inc/libmx.h"

void* mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    while (n--) {
        *((unsigned char *)dst) = *((unsigned char *)src);
        dst = (unsigned char *)dst + 1;
        src = (unsigned char *)src + 1;
    }
    return (unsigned char *)dst - n;
}
