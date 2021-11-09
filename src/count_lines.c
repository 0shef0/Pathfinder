#include "../inc/pathfinder.h"

int mx_count_lines_of_file(char *str){
    int count = 0;
    int len = mx_strlen(str);
    if(str[len - 1] != '\n'){
        count++;
    }
    count += mx_count_substr(str, "\n");
    return count;
}
