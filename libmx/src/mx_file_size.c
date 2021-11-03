#include "../inc/libmx.h"

int mx_file_size(const char *file) {
    int fl = open(file, O_RDONLY);
    int len = 0;
    char buf;
    while (read(fl, &buf, 1) > 0) {
        len++;
    }
    close(fl);
    return len;
}
