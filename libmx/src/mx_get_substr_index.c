#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub){
    if (!str || !sub){
        return -2;
    }
    int i = 0;
    if(mx_strstr(str, sub) != 0){
        while (str) {
            if(mx_strcmp(str, mx_strstr(str, sub)) == 0) {
                return i;
            } else {
                str++;
                i++;
            }
        }
    }
    str -= i;
    return -1;
}
