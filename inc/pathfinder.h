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

int mx_file_size(const char *file);
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
int island_index(char **islands, char *island);
void distance(int **dstns, char **islands, char *s, int dst);
int get_dist(char **nodes, int *weights, char *s);
void dijkstra(int *weights, char **islands, t_line **lines, int count);
int get_path(int *len, int *weights, char **islands, t_line **lines, int count_islands, char *from, char **path, int *blacklist, int *blked, int *permblkd);
void algorythm(int count_lines, char **arr_islands, t_line **lines, int real_count_of_islands);
void mx_print_path(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count);
bool is_visited(char **visited, char *s, int visits);
bool is_blacklisted(int c, int *blacklist, int size);


#endif
