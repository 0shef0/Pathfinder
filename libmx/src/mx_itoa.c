#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == -2147483648){
        char *str = mx_strnew(11);
        str = "-2147483648";
        return str;
    }
    if ( number == 0 ) {
        char * str = mx_strnew(1);
        str = "0";
        return str;
    }
    int i = 0;
    int flag = 0;
    int buf = number;
    if ( number < 0 ) {
        i++;
        buf *= -1;
        flag = 1;
    }
    while ( number != 0 ){
        i++;
        number /= 10;
    }
    char *str = mx_strnew(i + 1);
    if ( flag == 1 ) {
        *(str + 0) = '-';
        for (int j = i - 1 ; j >= 1; j--) {
            str[j] = (buf % 10) + 48;
            buf /= 10;
        }
    } else {
        for (int j = i - 1; j >= 0; j--) {
            str[j] = (buf % 10) + 48;
            buf /= 10;
        }
    }
    return str;
}

