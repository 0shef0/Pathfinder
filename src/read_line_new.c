#include "../inc/pathfinder.h"

int read_line_new(char **lineptr, char delim, int file_size, const int fd) {
    if (fd < 0) {
        return -2;
    }
    char *buffer = mx_strnew(file_size);
    int flag = 1;
    int count = 0;
    while (flag > 0){
        char *buf = mx_strnew(1);
        if ( (flag = read(fd, buf, 1)) > 0) {
            if (mx_strchr(buf, delim)) {
                free(buf);
                break;
            }
            count += 1;
            mx_strncat(buffer, buf, 1);
            free(buf);
        } else {
            free(buf);
            break;
        }
    }
    if ((count + flag) == 0) {
        mx_strcpy(*lineptr, buffer);
        free(buffer);
        if (flag == -1) {
            return -2;
        } else {
            return -1;
        }
    }
    mx_strcpy(*lineptr, buffer);
    free(buffer);
    return count;
}
