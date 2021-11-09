#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_line {
    char *island1;
    char *island2;
    int path;
}              t_line;

typedef struct s_island {
    char *island;
    struct s_island *next;
}              t_island;


void mx_printerr(const char *s);
int read_line_new(char **lineptr, char delim, int file_size, const int fd);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
void err_invalid_line_n(int line_number);
t_island *mx_create_node_island(char *island);
void mx_push_back_island(t_island **head, char *island);
int mx_list_size_islands(t_island *list);
int mx_count_lines_of_file(char *str);
void mx_pop_back_island(t_island **head);


#endif
