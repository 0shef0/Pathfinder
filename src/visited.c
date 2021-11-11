#include "../inc/pathfinder.h"

bool is_visited(char **visited, char *s, int visits) {
    int i = 0;
    while(i < visits) {
        if (!mx_strcmp(visited[i], s)) return true;
        i++;
    }
    return false;
}
