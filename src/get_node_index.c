#include "../inc/pathfinder.h"

int get_node_index(char **islands, char *island) {
    int i = 0;
    while(islands[i]) {
        if (mx_strcmp(islands[i], island) == 0) return -1;
        i++;
    }
    return i;
}
