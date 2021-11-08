#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) {


    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(0);
    }
    int file_size = mx_file_size(argv[1]);
    if (file_size == 0) {
        mx_printerr("error: file [filename] is empty\n");
        exit(0);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file [filename] does not exist\n");
        close(fd);
        exit(0);
    }

    char *str = mx_strnew(file_size);
    read(fd, str, file_size);
    close(fd);

    int indexn = mx_get_char_index(str, '\n');
    for ( int i = 0; i < indexn; i++){
        if(mx_isdigit(str[i]) != true){
            err_invalid_line_n(1);
            mx_strdel(&str);
        }
    }


    char *str_count = mx_strndup(str, indexn+1);
    int count_islands_file = mx_atoi(str_count);
    free(str_count);
    mx_printint(count_lines);
    str += indexn + 1;
    t_line lines[count_lines-1];

    int count_lines = count_lines(str);
    mx_printint(count_lines);


    int iterator = indexn + 1;
    for(int i = 0; i < count_lines - 1; i++){
        indexn = mx_get_char_index(str, '-');
        lines[i].island1 = mx_strndup(str, indexn); // освободить память
        str += indexn+1;
        iterator += indexn + 1;

        indexn = mx_get_char_index(str, ',');
        lines[i].island2 = mx_strndup(str, indexn); // освободить память
        str += indexn+1;
        iterator += indexn + 1;

        indexn = mx_get_char_index(str, '\n');
        char *buf;
        if( indexn == -1 ){
            indexn = mx_strlen(str);
        }
        buf = mx_strndup(str, indexn);
        for ( int j = 0; j < mx_strlen(buf); j++){
            if (mx_isdigit(buf[j]) != true){
                err_invalid_line_n(i + 2);
                str -= iterator;
                free(str);
                free(buf);
                exit(0);
            }
        }
        lines[i].path = mx_atoi(buf);
        free(buf);
        str += indexn + 1;
        iterator += indexn + 1;
    }


    str -= iterator;

    //==================================================================================================================
    //проверка на правильность строк
    for ( int i = 0; i < count_lines - 1; i++){
        for (int j = 0; j < mx_strlen(lines[i].island1); j++) {
            if (mx_isalpha(lines[i].island1[j]) != true) {
                err_invalid_line_n(i + 2);
                exit(0);
            }
        }
        for (int j = 0; j < mx_strlen(lines[i].island2); j++){
            if (mx_isalpha(lines[i].island2[j]) != true){
                err_invalid_line_n(i + 2);
                exit(0);
            }
        }
        if(lines[i].path <= 0){
            err_invalid_line_n(i + 2);
            exit(0);
        }
    }
    //==================================================================================================================

    //==================================================================================================================
    //создание списка островов
    t_island *islands;
    for ( int i = 0; i < count_lines - 1; i++){
        int flag = 0;
        t_island *tmp = islands;
        while(tmp){
            if(mx_strcmp(tmp->island, lines[i].island1) == 0){
                flag = 1;
            }
            tmp = tmp->next;
        }
        if (flag == 0){
            mx_push_back_island(&islands, lines[i].island1); // не забыть удалять
        }
        flag = 0;
        tmp = islands;
        while(tmp){
            if(mx_strcmp(tmp->island, lines[i].island2) == 0){
                flag = 1;
            }
            tmp = tmp->next;
        }
        if (flag == 0){
            mx_push_back_island(&islands, lines[i].island2); // не забыть удалять
        }
    }
    //==================================================================================================================

    int real_count_of_islands = mx_list_size_islands(islands);
    if(real_count_of_islands != count_islands_file){
        mx_printerr("error: invalid count of islands");
        while(islands){
            free(islands->island);
            islands->island = NULL;
        }
        for(int i = 0; i < count_lines - 2; i++){
            lines
        }
        free(str);
    }

    free(str);
}


