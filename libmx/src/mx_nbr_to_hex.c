#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if ( nbr == 0 ) {
        char *str = mx_strnew(1);
        str = "0";
        return str;
    }
    long buf = nbr;
    int count = 0;
    while (buf != 0) {
        count++;
        buf /= 16;
    }
    if ( count == 0 ){
        return 0;
    }
    char *str = mx_strnew(count);
    for (int i = 0; i < count; i++){
        if ( nbr % 16 < 10 ) {
            *(str + count - i - 1) = (nbr % 16) + 48;
        } else {
            *(str + count - i - 1) = (nbr % 16) + 87;
        }
        nbr /= 16;
    }
    return str;
}
