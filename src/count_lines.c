#include "../inc/pathfinder.h"

int mx_count_lines(char *str){
    int count = 0;
    if(str[mx_strlen(str) - 1] != '\n'){
        count++;
    }
    count += mx_count_chr(str, '\n');
    return count;
}
