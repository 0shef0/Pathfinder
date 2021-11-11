#include "../inc/pathfinder.h"

bool is_visited(char **visited, char *s, int visits) {
    int i = 0;
    while(i < visits) {
        if (!mx_strcmp(visited[i], s)) return true;
        i++;
    }
    return false;
}

void dijkstra(int *weights, char **islands, t_line **lines, int count_islands)
{
    char **v = malloc(count_islands * sizeof *v);
    char *curr;
    int visits = 0;
    int i = 0;
    while ( i < count_islands ) {
        int weight = 0;
        int min = 0;
        while (is_visited(v, islands[min], visits)) min++;
        if (visits == count_islands) break;
        int j = 0;
        while ( j < count_islands){
            if (is_visited(v, islands[j], visits)) {
                j++;
                continue;
            }
            if (weights[j] >= 0 && (weights[min] < 0 || weights[min] > weights[j]))
            {
                min = j;
            }
            j++;
        }
        curr = islands[min];
        j = 0;
        while ( j < count_islands){
            if (!mx_strcmp(lines[j]->island1, curr)) {
                if (is_visited(v, lines[j]->island2, visits)) {
                    j++;
                    continue;
                }
                weight = get_dist(islands, weights, curr);
                mx_set_weight(&weights, islands, lines[j]->island2, weight + lines[j]->path);
            } else if (!mx_strcmp(lines[j]->island2, curr)) {
                if (is_visited(v, lines[j]->island1, visits)) {
                    j++;
                    continue;
                }
                weight = get_dist(islands, weights, curr);
                mx_set_weight(&weights, islands, lines[j]->island1, weight + lines[j]->path);
            }
            j++;
        }
        v[visits] = curr;
        visits++;
        i++;
    }
    free(v);
}
