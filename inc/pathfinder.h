#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_line {
    char *island1;
    char *island2;
    int path;
    s_line *next;
}              t_line;

typedef struct s_arr_elem {
    char *island;
    int id;
}              t_arr_elem;

typedef struct s_matrix_elem {
    int row;
    int collum;
    bool route;
}              t_matrix_elem;

void mx_printerr(const char *s);
int read_line_new(char **lineptr, char delim, int file_size, const int fd);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
bool mx_check_string(char *str);
void err_invalid_line_n(int line_number);
void mx_push_front_new(t_line **list, char *island1, char *island2, int path);
t_line *mx_create_node_new(char *island1, char *island2, int path);
void mx_push_back_new(t_line **list, char *island1, char *island2, int path);

#endif