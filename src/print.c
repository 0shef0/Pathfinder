#include "../inc/pathfinder.h"

bool is_blacklisted(int c, int *blacklist, int size) {
    int i = 0;
    while( i < size ) {
        if (blacklist[i] == c) {
            return true;
        }
        i++;
    }
    return false;
}

int get_path(int *len, int *weights, char **islands, t_line **lines, int count_islands, char *from, char **path, int *blacklist, int *blked, int *permblkd)
{
    int cur_len = 0;
    int cur_weight = -1;
    int from_weight = 0;
    int steps = 1;
    char *cur_node = from;
    int prev_bridge_i = -1;
    path[0] = from;
    int needed_bridge = -1;
    bool break_flag = true;
    bool fell = true;
    int j = 0;
    while((j < count_islands + 1) && break_flag) {
        fell = true;
        from_weight = get_dist(islands, weights, from);
        int i = 0;
        while(i < count_islands) {
            if (is_blacklisted(i, blacklist, *blked)) {
                i++;
                continue;
            }
            if (!mx_strcmp(lines[i]->island1, from)) {
                cur_node = lines[i]->island2;
                cur_weight = get_dist(islands, weights, lines[i]->island2);
                cur_len = lines[i]->path;
            } else if (!mx_strcmp(lines[i]->island2, from)) {
                cur_node = lines[i]->island1;
                cur_weight = get_dist(islands, weights, lines[i]->island1);
                cur_len = lines[i]->path;
            }
            else {
                i++;
                continue;
            }
            if (from_weight < cur_len) {
                i++;
                continue;
            }
            if (cur_weight == 0) {
                blacklist[*blked] = i;
                *blked += 1;
                path[steps] = cur_node;
                len[steps - 1] = cur_len;
                steps++;
                break_flag = false;
                fell = false;
                needed_bridge = i;
                break;
            }
            if (from_weight - cur_len == cur_weight) {
                prev_bridge_i = i;
                len[steps - 1] = cur_len;
                from = cur_node;
                path[steps] = from;
                steps++;
                fell = false;
                break;
            }
            i++;
        }
        if (fell == true) {
            if (!mx_strcmp(from, path[0])) {
                return -1;
            }
            j = 0;
            from = path[0];
            steps = 1;
            blacklist[*blked] = prev_bridge_i;
            *blked += 1;
            if (!mx_strcmp(lines[prev_bridge_i]->island1, path[0])
                || !mx_strcmp(lines[prev_bridge_i]->island2, path[0])) {
                blacklist[*permblkd] = prev_bridge_i;
                *permblkd += 1;
                *blked = *permblkd;
            }
        }
        if (!break_flag && (!mx_strcmp(lines[needed_bridge]->island1, path[0])
                            || !mx_strcmp(lines[needed_bridge]->island2, path[0]))) {
            blacklist[*permblkd] = needed_bridge;
            *permblkd += 1;
            *blked = *permblkd;
        }
        j++;
    }
    path[steps] = NULL;
    return steps;
}

void mx_print_path(int *weights, char **nodes, t_line **bridges, int count, char *from, int bridge_count)
{
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
