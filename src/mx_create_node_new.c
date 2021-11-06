#include "../inc/pathfinder.h"

t_line *mx_create_node_new(char *island1, char *island2, int path) {
    t_line *new_node = (t_line*)malloc(sizeof(t_line*));
    new_node->next = NULL;
    new_node->path = path;
    new_node->island1 = island1;
    new_node->island2 = island2;
    return new_node;
}
