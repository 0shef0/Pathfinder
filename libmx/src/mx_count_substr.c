#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }
    int count = 0;
    char *buf = mx_strdup(str);
    while (mx_strstr(buf, sub) != 0) {
        count++;
        buf += mx_get_substr_index(buf, sub) + 1;
    }
    return count;
}
