#include "../inc/pathfinder.h"

void algorythm(int count_lines, char **arr_islands, t_line **lines, int real_count_of_islands) {
    t_line *tmp;
    for (int i = 0; i < count_lines; i++) {
        for (int j = i + 1; j < count_lines; j++) {
            if ((island_index(arr_islands, lines[i]->island1) +
                    island_index(arr_islands, lines[i]->island2)) >
                        (island_index(arr_islands, lines[j]->island1) +
                            island_index(arr_islands, lines[j]->island2))) {
                tmp = lines[i];
                lines[i] = lines[j];
                lines[j] = tmp;
            }
        }
    }
    int *dstns = malloc((real_count_of_islands + 1) * sizeof(int));
    for (int i = 0; i < real_count_of_islands - 1; i++) {
        for (int j = i + 1; j < real_count_of_islands; j++) {
            for (int k = 0; k < real_count_of_islands; k++) dstns[k] = -1;
            distance(&dstns, arr_islands, arr_islands[j], 0);
            dijkstra(dstns, arr_islands, lines, real_count_of_islands);
            mx_print_path(dstns, arr_islands, lines, real_count_of_islands, arr_islands[i], count_lines);
        }
    }
    free(dstns);
}
