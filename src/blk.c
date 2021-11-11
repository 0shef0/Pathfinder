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
