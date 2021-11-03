#include "../inc/libmx.h"

void* mx_memccpy(void *restrict dest, const void *restrict src, int c, size_t n) {
    char *tmp_dest = (char *)dest;
    const char *tmp_src = (const char *)src;
    while (n-- || *tmp_src == c) {
        *tmp_dest++ = *tmp_src++;
    }
    return dest;
}
