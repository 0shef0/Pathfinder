#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = 0;
    unsigned long num = 0;
    unsigned long h = 1;

    if (hex) {
        while (hex[len]) {
            len++;
        }
    } else {
        return 0;
    }
        for (int i = len; i >= 0; i--) {
            if (hex[i] > 47 && hex[i] < 58) {
                num += (hex[i] - 48) * h;
                h *= 16;
            }
            if (hex[i] > 64 && hex[i] < 71) {
                num += (hex[i] - 55) * h;
                h *= 16;
            }
            if (hex[i] > 96 && hex[i] < 103) {
                num += (hex[i] - 87) * h;
                h *= 16;
            }
        }
    return num;
}
