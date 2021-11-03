#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    int i = 0;
    while (s[i]) {
        if (s[i] == c) {
            char *symb = (char *)&s[i];
            return symb;
        }
        i++;
    }
    return 0;
}
