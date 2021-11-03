#include "../inc/pathfinder.h"

bool mx_check_string(char *str){
    for (int i = 0; i < mx_strlen(str); i++){
        if(mx_isalpha(str[i])== false){
            return false;
        }
    }
    return true;
}