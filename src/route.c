#include "../inc/pathfinder.h"

int get_path(int *len, int *dstns, char **islands, t_line **lines, int count_islands, char *from, char **path, int *blacklist, int *blked, int *permblkd)
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
        from_weight = get_dist(islands, dstns, from);
        int i = 0;
        while(i < count_islands) {
            if (is_blacklisted(i, blacklist, *blked)) {
                i++;
                continue;
            }
            if (!mx_strcmp(lines[i]->island1, from)) {
                cur_node = lines[i]->island2;
                cur_weight = get_dist(islands, dstns, lines[i]->island2);
                cur_len = lines[i]->path;
            } else if (!mx_strcmp(lines[i]->island2, from)) {
                cur_node = lines[i]->island1;
                cur_weight = get_dist(islands, dstns, lines[i]->island1);
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
