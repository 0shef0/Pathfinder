#include "../inc/libmx.h"

char *mx_strcat(char *s1, const char *s2) {
    int j = 0;
    for (int i = mx_strlen(s1); i < mx_strlen(s2) + mx_strlen(s1); i++) {
        *(s1 + i) = *(s2 + j);
        j++;
    }
    return s1;
}
