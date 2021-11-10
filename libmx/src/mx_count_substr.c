#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }
    int count = 0;
    while (mx_strstr(str, sub) != 0) {
        count++;
        str += mx_get_substr_index(str, sub) + 1;
    }
    return count;
}
