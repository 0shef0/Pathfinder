#include "../inc/libmx.h"

bool mx_isspace(int c) {
    if ((c > 8
        && c < 14 )
        || c == 32) {
        return true;
    } else {
        return false;
    }
}
