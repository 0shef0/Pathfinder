#include "../inc/pathfinder.h"

int main (int argc, char *argv[]){
    if(argc != 2){
        mx_printerr("usage: ./pathfinder [filename]\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0){
        mx_printerr("error: file [filename] does not exist\n");
        close(fd);
        return -1;
    }
    int file_size = mx_file_size(argv[1]);
    if (file_size == 0){
        mx_printerr("error: file [filename] is empty\n");
        close(fd);
        return -1;
    }


    char *str_count_islands = mx_strnew(11);
    read_line_new(&str_count_islands, '\n', file_size, fd);
    for (int i = 0; i < mx_strlen(str_count_islands); i++){
        if(mx_isdigit(str_count_islands[i]) == false){
            mx_printerr("error: line 1 is not valid\n");
            close(fd);
            free(str_count_islands);
            return -1;
        }
    }
    int count_islands = mx_atoi(str_count_islands);
    free(str_count_islands);


    int count_lines = 1;
    int tmp = 0;
    int iterrator = 0;
    t_line **arr = (t_line **) malloc(count_islands * sizeof (t_line *));
    while (tmp > 0){
        count_lines++;


        char *buf = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf,'-',file_size,fd);
        if(mx_check_string(buf) == false || tmp < 0){
            err_invalid_line_n(count_lines);
            close(fd);
            for ( int i = 0; i < count_islands; i++) {
                free(arr[i]);
            }
            free(buf);
            return -1;
        }
        //arr[iterrator]->island = (char *)malloc(sizeof char*);
        mx_strcpy(arr[iterrator]->island, buf);
        free(buf);


        char *buf = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf, ',', file_size, fd);
        if(mx_check_string(buf) == false || tmp < 0){
            err_invalid_line_n(count_lines);
            close(fd);
            for ( int i = 0; i < count_islands; i++) {
                free(arr[i]);
            }
            free(buf);
            return -1;
        }
        //arr[iterrator]->next = (char *)malloc(sizeof char*);
        mx_strcpy(arr[iterrator]->next, buf);
        free(buf);


        char *buf = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf, '\n', file_size, fd);
        for (int i = 0; i < mx_strlen(buf); i++){
            if(mx_isdigit(buf[i]) == false){
                err_invalid_line_n(count_lines);
                close(fd);
                for ( int i = 0; i < count_islands; i++) {
                    free(arr[i]);
                }
                free(buf);
                return -1;
            }
        }
        arr[iterrator]->path = mx_atoi(buf);
        if(arr[iterrator]->path <= 0){
            err_invalid_line_n(count_lines);
            close(fd);
            for ( int i = 0; i < count_islands; i++) {
                free(arr[i]);
            }
            free(buf);
            return -1;
        }
        free(buf);
    }
    for (int i = 0; i < count_lines - 1; i++){
        for(int j = i+1; j < count_lines - 2; j++) {
            if ((mx_strcmp(arr[i]->island, arr[j]->island) == 0
                    && mx_strcmp(arr[i]->next, arr[j]->next) == 0)
                        || (mx_strcmp(arr[i]->next, arr[j]->island) == 0
                             && mx_strcmp(arr[i]->island, arr[j]->next) == 0)){
                mx_printerr("error: duplicate bridges");
                for ( int i = 0; i < count_islands; i++) {
                    free(arr[i]);
                }
                close(fd);
                return -1;
            }
        }
    }
}