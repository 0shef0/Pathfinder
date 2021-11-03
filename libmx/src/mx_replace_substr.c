#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }
    int j = mx_count_substr(str, sub);
    if ( j < 0 ){
        return mx_strdup(str);
    }
    char *new_str = mx_strnew(mx_strlen(str) - (j * mx_strlen(sub)) + (j * mx_strlen(replace)));
    mx_strcpy(new_str, str);
    while (mx_strstr(new_str, sub) != 0) {
        char *buf = mx_strnew(mx_strlen(new_str) - mx_strlen(sub) + mx_strlen(replace));
        int n = mx_get_substr_index(new_str, sub);
        mx_strncpy(buf, new_str, n);
        for ( int i = n, j = 0; j < mx_strlen(replace);j++, i++){
            buf[i] = replace[j];
        }
        for ( int i = 0; i < mx_strlen(new_str); i++) {
            buf[i + n + mx_strlen(replace)] = new_str[i + n + mx_strlen(sub)];
        }
        mx_strcpy(new_str, buf);
        free(buf);
    }
    return new_str;
}
