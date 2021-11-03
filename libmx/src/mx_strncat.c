#include "../inc/libmx.h"

char *mx_strncat(char *restrict1, const char *restrict2, int n) {
    if ( n > mx_strlen(restrict1) + mx_strlen(restrict2)){
        n = mx_strlen(restrict1) + mx_strlen(restrict2);
    }
    for (int i = mx_strlen(restrict1), j = 0; j < n; i++, j++) {
        *(restrict1 + i) = *(restrict2 + j);
    }
    return restrict1;
}
