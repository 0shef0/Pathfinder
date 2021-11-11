#include "../inc/pathfinder.h"

void distance(int **dstns, char **islands, char *s, int dst) {
    int i = 0;
    while(islands[i]){
        if (!mx_strcmp(islands[i], s)) {
            if ((*dstns)[i] < dst && (*dstns)[i] > 0) return;
            (*dstns)[i] = dst;
            return;
        }
        i++;
    }
}
