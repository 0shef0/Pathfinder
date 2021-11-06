#include "../inc/pathfinder.h"

void mx_push_back_new(t_line **list, char *island1, char *island2, int path) {
    if (!*list) {
        *list = mx_create_node_new(island1, island2, path);
        return;
    }
    t_line *tmp = *list;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    t_line *back = mx_create_node_new(island1, island2, path);
    tmp->next = back;
}
