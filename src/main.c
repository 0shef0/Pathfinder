#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }

    int file_size = mx_file_size(argv[1]);

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        close(fd);
        exit(0);
    }

    if (file_size == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(0);
    }

    char *str = mx_strnew(file_size);
    read(fd, str, file_size);
    close(fd);

    int indexn = mx_get_char_index(str, '\n');
    for ( int i = 0; i < indexn; i++){
        if(mx_isdigit(str[i]) != true){
            err_invalid_line_n(1);
            free(str);
            exit(0);
        }
    }


    char *str_count = mx_strndup(str, indexn);
    int count_islands_file = mx_atoi(str_count);
    free(str_count);


    int count_lines = mx_count_lines_of_file(str) - 1;
    str += indexn + 1;
    t_line **lines = NULL;
    lines = malloc((count_lines + 1) * sizeof(t_line));


    int iterator = indexn + 1;
    for(int i = 0; i < count_lines; i++){
        lines[i] = NULL;
        lines[i] = malloc(sizeof(t_line));
        indexn = mx_get_char_index(str, '-');
        lines[i]->island1 = mx_strndup(str, indexn);
        str += indexn+1;
        iterator += indexn + 1;

        indexn = mx_get_char_index(str, ',');
        lines[i]->island2 = mx_strndup(str, indexn);
        str += indexn+1;
        iterator += indexn + 1;

        indexn = mx_get_char_index(str, '\n');
        if( indexn == -1 ){
            indexn = mx_strlen(str);
        }
        char * buf = mx_strndup(str, indexn);
        lines[i]->path = mx_atoi(buf);
        free(buf);
        str += indexn + 1;
        iterator += indexn + 1;
    }

    str -= iterator;
    free(str);

    for ( int i = 0; i < count_lines; i++){
        for (int j = 0; j < mx_strlen(lines[i]->island1); j++) {
            if (mx_isalpha(lines[i]->island1[j]) != true) {
                err_invalid_line_n(i + 2);
                for(int k = 0; k < count_lines; k++){
                    mx_strdel(&lines[k]->island1);
                    mx_strdel(&lines[k]->island2);
                    free(lines[k]);
                }
                free(lines);
                exit(0);
            }
        }
        for (int j = 0; j < mx_strlen(lines[i]->island2); j++){
            if (mx_isalpha(lines[i]->island2[j]) != true){
                err_invalid_line_n(i + 2);
                for(int k = 0; k < count_lines; k++){
                    mx_strdel(&lines[k]->island1);
                    mx_strdel(&lines[k]->island2);
                    free(lines[k]);
                }
                free(lines);
                exit(0);
            }
        }
        if(lines[i]->path <= 0){
            err_invalid_line_n(i + 2);
            for(int k = 0; k < count_lines; k++){
                mx_strdel(&lines[k]->island1);
                mx_strdel(&lines[k]->island2);
                free(lines[k]);
            }
            free(lines);
            exit(0);
        }
    }

    t_island *islands = mx_create_node_island(lines[0]->island1);
    for ( int i = 0; i < count_lines; i++){
        int flag = 0;
        t_island *tmp = islands;
        while(tmp){
            if(mx_strcmp(tmp->island, lines[i]->island1) == 0){
                flag = 1;
            }
            tmp = tmp->next;
        }
        if (flag == 0){
            mx_push_back_island(&islands, lines[i]->island1);
        }
        flag = 0;
        tmp = islands;
        while(tmp){
            if(mx_strcmp(tmp->island, lines[i]->island2) == 0){
                flag = 1;
            }
            tmp = tmp->next;
        }
        if (flag == 0){
            mx_push_back_island(&islands, lines[i]->island2);
        }
    }

    int real_count_of_islands = mx_list_size_islands(islands);
    if(real_count_of_islands != count_islands_file){
        mx_printerr("error: invalid count of islands\n");
        while(islands){
            mx_pop_back_island(&islands);
        }
        for(int k = 0; k < count_lines; k++){
            mx_strdel(&lines[k]->island1);
            mx_strdel(&lines[k]->island2);
            free(lines[k]);
        }
        free(lines);
        exit(0);
    }

    char *arr_islands[real_count_of_islands];
    t_island *tmp = islands;
    for(int i = 0; i < real_count_of_islands; i++){
        arr_islands[i] = mx_strdup(tmp->island);
        tmp = tmp->next;
    }

    int matrix[real_count_of_islands][real_count_of_islands];
    for (int i = 0; i < real_count_of_islands; i++){
        for(int j = 0; j < real_count_of_islands; j++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < count_lines; i++){
        for(int j = 0; j < real_count_of_islands; j++){
            if(mx_strcmp(lines[i]->island1, arr_islands[j]) == 0){
                for(int k = 0; k < real_count_of_islands; k++){
                    if(mx_strcmp(lines[i]->island2, arr_islands[k]) == 0) {
                        matrix[j][k] = lines[i]->path;
                        matrix[k][j] = lines[i]->path;
                    }
                }
            }
        }
    }

    algorythm(count_lines, arr_islands, lines, real_count_of_islands);

    while (islands){
        mx_pop_back_island(&islands);
    }

    for(int i = 0; i < real_count_of_islands; i++){
        free(arr_islands[i]);
    }
    for(int i = 0; i < count_lines; i++) {
        free(lines[i]->island1);
        free(lines[i]->island2);
        free(lines[i]);
    }
    free(lines);
}





