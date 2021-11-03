#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int a = 0;
    int b = 1;
    if (x < 0) {
        return 0;
    }
    while (a != b) {
        a = x / b;
        if (a == b){
            return b;
        }
        b++;
        if (b > x) {
            return 0;
        }
    }
    return 0;
}
