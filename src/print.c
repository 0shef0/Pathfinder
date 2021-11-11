#include "../inc/pathfinder.h"

void mx_print_path(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count) {
    int *len = malloc(count * sizeof *len);
    char **path = malloc((count + 1) * sizeof *path);
    path[count] = NULL;
    int *blacklist = malloc(bridge_count * sizeof *blacklist);
    int perm_blocked = 0;
    int blocked = 0;
    while (true)
    {
        int steps = get_path(len, weights, nodes, bridges, count, from, path, blacklist, &blocked, &perm_blocked);
        if (steps == -1) {
            break;
        }

        for (int i = 0; i < 40; i++) {
            mx_printchar('=');
        }
        mx_printchar('\n');

        mx_printstr("Path: ");
        mx_printstr(path[0]);
        mx_printstr(" -> ");
        mx_printstr(path[steps - 1]);
        mx_printchar('\n');
        mx_printstr("Route: ");
        for(int i = 0; i < steps; i++){
            mx_printstr(path[i]);
            if ( i != steps - 1) {
                mx_printstr(" -> ");
            }
        }
        mx_printchar('\n');
        mx_printstr("Distance: ");
        int sum = 0;
        for (int i = 0; i < steps - 1; i++)
        {
            sum += len[i];
            mx_printint(len[i]);
            if (i + 1 != steps - 1) mx_printstr(" + ");
        }
        if (sum != len[0])
        {
            mx_printstr(" = ");
            mx_printint(sum);
        }
        mx_printchar('\n');
        for (int i = 0; i < 40; i++) mx_printchar('=');
        mx_printchar('\n');
    }
    free(len);
    free(path);
    free(blacklist);
}
