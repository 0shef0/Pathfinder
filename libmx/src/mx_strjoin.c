#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if ( s1 == NULL && s2 == NULL ){
        return NULL;
    } else if ( s1 == NULL || s2 == NULL ) {
        if ( s1 == NULL ) {
            return mx_strdup(s2);
        } else {
            return mx_strdup(s1);
        }
    } else {
        char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        str = mx_strcat(str, s1);
        str = mx_strcat(str, s2);
        return str;
    }
}
