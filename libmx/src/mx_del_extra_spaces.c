#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *string = mx_strnew(mx_strlen(str));
    int count = 0;
    for ( int i = 0; i < mx_strlen(str); i++){
        if ( mx_isspace(str[i]) == 0) {
            *(string + count) = str[i];
            count++;
        }
        if (mx_isspace(str[i]) == 0 && mx_isspace(str[i + 1]) == 1) {
            if ( i < mx_strlen(str) - 1) {
                *(string + count) = ' ';
                count++;
            }
        }
    }
    char *res = mx_strnew(count - 1);
    char *result = mx_strncpy(res, string, count - 2);
    mx_strdel(&string);

    return result;
}
