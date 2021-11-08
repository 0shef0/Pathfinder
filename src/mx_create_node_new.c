#include "../inc/pathfinder.h"

t_island *mx_create_node_island(char *island) {
    t_island *new_node = malloc(sizeof (t_island));
    new_node->next = NULL;
    new_node->island = island;
    return new_node;
}
