#include "../inc/pathfinder.h"

int mx_list_size_islands(t_island *list) {
    int size = 0;
    while (list) {
        list = list->next;
        size++;
    }
    return size;
}
