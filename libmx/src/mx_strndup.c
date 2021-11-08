#include "../inc/libmx.h"

char *mx_strndup(const char *str, size_t n){
    char *d;
    if (mx_strlen(str) > (int)n) {
        d = mx_strnew(n);
    } else {
        d = mx_strnew(mx_strlen(str));
    }
    if (d == NULL) {
        return NULL;
    }
    mx_strncpy (d, str, n);
    return d;
}
