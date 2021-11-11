#include "../inc/pathfinder.h"

int get_dist(char **islands, int *weights, char *island) {
    int i = 0;
    while (islands[i]){
        if (!mx_strcmp(islands[i], island)) return weights[i];
        i++;
    }
    return 0;
}
