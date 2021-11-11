#include "../inc/pathfinder.h"

void mx_set_weight(int **weights, char **nodes, char *s, int weight) {
    int i = 0;
    while(nodes[i]){
        if (!mx_strcmp(nodes[i], s)) {
            if ((*weights)[i] < weight && (*weights)[i] > 0) return;
            (*weights)[i] = weight;
            return;
        }
        i++;
    }
}
