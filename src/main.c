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
    int tmp = 1;
    t_line *lines;

    while (tmp > 0){
        count_lines++;

        char *buf1 = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf1,'-',file_size,fd);
        if(mx_check_string(buf1) == false || tmp < 0) {
            err_invalid_line_n(count_lines);
            while (lines){
                mx_pop_front(*lines);
            }
            close(fd);
            free(buf1);
            return -1;
        }


        char *buf2 = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf2, ',', file_size, fd);
        if(mx_check_string(buf2) == false || tmp < 0) {
            err_invalid_line_n(count_lines);
            while (lines){
                mx_pop_front(*lines);
            }
            close(fd);
            free(buf2);
            return -1;
        }

        char *buf3 = (char *)malloc(sizeof char*);
        tmp = read_line_new(&buf3, '\n', file_size, fd);
        for (int i = 0; i < mx_strlen(buf3); i++) {
            if (mx_isdigit(buf[i]) == false) {
                err_invalid_line_n(count_lines);
                while (lines){
                    mx_pop_front(*lines);
                }
                close(fd);
                free(buf3);
                return -1;
            }
        }

        int path = mx_atoi(buf3);
        if(path <= 0){
            err_invalid_line_n(count_lines);
            while (lines){
                mx_pop_front(*lines);
            }
            close(fd);
            free(buf3);
            return -1;
        }
        mx_push_back_new(*lines, buf1, buf2, path);
        free(buf1);
        free(buf2);
        free(buf3);
    }

    char *arr[(count_lines-1)*2];
    t_line *temp = lines;
    for (int i = 0; i < (count_lines-1)*2; i++){
        arr[i] = mx_strdup(temp->island1);
        i++;
        arr[i] = mx_strdup(temp->island2);
        if(i != (count_lines-1)*2 - 1) {
            temp = temp->next;
        }
    }

    for (int i = 0; i < (count_lines-1)*2 - 2; i++){
        for(int j = i + 2; j < (count_lines-1)*2; j++){
            if((mx_strcmp(arr[i], arr[j]) == 0 && mx_strcmp(arr[i+1], arr[j+1]) == 0) || (mx_strcmp(arr[i], arr[j+1]) == 0 &&
                    mx_strcmp(arr[i+1], arr[j]) == 0)) {
                mx_printerr("error: duplicate bridges");
                while (lines){
                    mx_pop_front(*lines);
                }
                close(fd);
                return -1;
            } else {
                j++;
            }
        }
        i++;
    }

    t_arr_elem *arr_islands[count_lines];
    t_line *line_buf = lines;




}
