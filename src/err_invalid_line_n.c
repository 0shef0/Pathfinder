#include "../inc/pathfinder.h"

void err_invalid_line_n(int line_number){
    mx_printerr("error: line ");
    char *buf = mx_itoa(line_number);
    mx_printerr(buf);
    free(buf);
    mx_printerr(" is not valid\n");
}
