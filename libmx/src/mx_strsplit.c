#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }
    int i = 0;
    char **arr = (char **)malloc((mx_count_words(s, c) + 1) * sizeof(char *));
    while (*s && *s != '\0'){
        if(*s != c) {
            size_t len = mx_count_chr(s, c);
            arr[i] = mx_strndup(s, len);
            s += len;
            i++;
        } else {
            s++;
        }
    }
    return arr;
}
