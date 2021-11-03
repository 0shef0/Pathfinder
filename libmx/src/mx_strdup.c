#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    char *d = mx_strnew(mx_strlen(str));
    if (d == NULL){
        return NULL;
    }
    mx_strcpy (d, str);
    return d;
}
