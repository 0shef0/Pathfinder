#include "../inc/libmx.h"

int mx_count_chr(const char *s, char delim){
    int count = 0;
    while (s && *s != delim) {
        count++;
        s++;
    }
    return count;
}
