#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (!str || !c) {
        return -1;
    }
    int flag = 0;
    int count = 0;
    for ( int i = 0; i <= mx_strlen(str) - 1; i++){
        if ( str[i] != c && str[i+1] == c) {
            flag = 1;
        }
        if (flag == 1) {
            count++;
            flag = 0;
        }
        if ( i == mx_strlen(str) - 1 && str[i] != c){
            count++;
        }
    }
    return count;
}
