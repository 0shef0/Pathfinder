#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int fl = open(file, O_RDONLY);
    if (fl == -1) {
        close(fl);
        return NULL;
    }
    int size = mx_file_size(file);
    if (size == 0)
        return NULL;
    char *newstr = mx_strnew(size);
    read(fl, newstr, size);
    close(fl);
    return newstr;
}
