#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_line {
    char *island;
    char *next;
    int path;
}              t_line;

void mx_printerr(const char *s);
int read_line_new(char **lineptr, char delim, int file_size, const int fd);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
bool mx_check_string(char *str);
void err_invalid_line_n(int line_number);

#endif