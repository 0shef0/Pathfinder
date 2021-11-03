#include "../inc/pathfinder.h"

int read_line_new(char **lineptr, char delim, int file_size, const int fd) {
    if (!fd || buf_size == 0) {
        return -2;
    }
    char *buffer = mx_strnew(file_size);
    int buf_size = 1;
    int flag;
    int count = 0;
    while (flag > 0){
        char *buf = mx_strnew(buf_size);
        if ( (flag = read(fd, buf, buf_size)) > 0) {
            if (mx_strchr(buf, delim)) {
                free(buf);
                break;
            }
            count += buf_size;
            mx_strncat(buffer, buf, buf_size);
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