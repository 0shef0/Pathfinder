#include "../inc/pathfinder.h"

void mx_push_front_new(t_line **list, char *island1, char *island2, int path) {
    if (!*list) {
        *list = mx_create_node(island1, island2, path);
        return;
    }
    t_line *nxt = mx_create_node(island1, island2, path);
    nxt->next = *list;
    *list = nxt;
}
