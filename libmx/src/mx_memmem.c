#include "../inc/libmx.h"

void* mx_memmem(void* buf,size_t buflen,void* pat,size_t patlen) {
    void* end = (char*)buf + buflen - patlen;
    while(buf == mx_memchr(buf,((char*)pat)[0],buflen)) {
        if(buf > end) {
            return 0;
        }
        if(mx_memcmp(buf, pat, patlen) == 0) {
            return buf;
        }
        buf = (char*)buf + 1;
    }
    return 0;
}
