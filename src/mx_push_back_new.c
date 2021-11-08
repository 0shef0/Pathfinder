#include "../inc/pathfinder.h"

void mx_push_back_island(t_island **head, char *island) {
    if (!*head) {
        *head = mx_create_node_island(island);
        return;
    }
    t_island *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    t_island *back = mx_create_node_island(island);
    tmp->next = back;
}
