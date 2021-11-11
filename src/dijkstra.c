#include "../inc/pathfinder.h"

void dijkstra(int *dstns, char **islands, t_line **lines, int count_islands)
{
    char **v = malloc(count_islands * sizeof *v);
    char *curr;
    int visits = 0;
    int i = 0;
    while ( i < count_islands ) {
        int dst = 0;
        int min = 0;
        while (is_visited(v, islands[min], visits)) min++;
        if (visits == count_islands) break;
        int j = 0;
        while ( j < count_islands){
            if (is_visited(v, islands[j], visits)) {
                j++;
                continue;
            }
            if (dstns[j] >= 0 && (dstns[min] < 0 || dstns[min] > dstns[j]))
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
                dst = get_dist(islands, dstns, curr);
                distance(&dstns, islands, lines[j]->island2, dst + lines[j]->path);
            } else if (!mx_strcmp(lines[j]->island2, curr)) {
                if (is_visited(v, lines[j]->island1, visits)) {
                    j++;
                    continue;
                }
                dst = get_dist(islands, dstns, curr);
                distance(&dstns, islands, lines[j]->island1, dst + lines[j]->path);
            }
            j++;
        }
        v[visits] = curr;
        visits++;
        i++;
    }
    free(v);
}
