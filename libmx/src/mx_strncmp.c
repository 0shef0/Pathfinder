#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, int n) {
    int lenth = 1;
    int i = 0;
    while(n != lenth && s1[i] == s2[i]) {
        i++;
        lenth++;
    }
    int res = (int)s1[i] - (int)s2[i];
    return res;
}
