#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim){
    if (!arr || !delim) {
        return;
    }
    int i = 0;
    while (*arr){
        i++;
        arr++;
    }
    arr -= i;
    for (int j = 0; j < i - 1; j++) {
        if (j != 0) {
            mx_printstr(delim);
        }
        mx_printstr(arr[j]);
    }
    mx_printchar('\n');
}
