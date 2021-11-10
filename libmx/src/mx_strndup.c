#include "../inc/libmx.h"

char *mx_strndup(const char *str, size_t n){
    char *d = NULL;
    size_t len = mx_strlen(str);
    if ( n < len){
        len = n;
    }
    d = mx_strnew(len);
    mx_strncpy (d, str, n);
    return d;
}
