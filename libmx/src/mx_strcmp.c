#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2) {
    while(*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    int res = (int)*s1 - (int)*s2;
    return res;
}
