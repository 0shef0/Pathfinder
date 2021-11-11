#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    for ( int i = 0; i < mx_strlen(str); i++){
        if(!mx_isdigit(str[i])){
            return -1;
        }
    }
    long int num = 0;
    int buf = 1;
    int i = 0;
    if (str[0] == '-') {
        buf *= -1;
        str++;
        i++;
    }
    while (*str) {
        if (*str > 47
            && *str < 58) {
            num *= 10;
            int buf_str = *str;
            num += buf_str - 48;
            if ( num > 2147483647 ) {
                return 0;
            } else if ( num < -2147483648) {
                return 0;
            }
        } else {
            if (buf < 0) {
                num *= -1;
                return (int)num;
            } else {
                return (int)num;
            }
        }
        str++;
        i++;
    }
    str -= i;
    if (buf < 0) {
        return (int)-num;
    } else {
        return (int)num;
    }
}
