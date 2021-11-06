#include "../inc/pathfinder.h"

void err_invalid_line_n(int line_number){
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line_number));
    mx_printerr(" is not valid");
}
