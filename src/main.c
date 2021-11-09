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
    //mx_printint(count_islands_file);


    int count_lines = mx_count_lines_of_file(str);
    str += indexn + 1;
    //mx_printint(count_lines);
    t_line lines[count_lines-1];


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
        if( indexn == -1 ){
            indexn = mx_strlen(str);
        }

        lines[i].path = mx_atoi(mx_strndup(str, indexn));
        str += indexn + 1;
        iterator += indexn + 1;
    }


    str -= iterator;
    mx_strdel(&str);

    //==================================================================================================================
    //проверка на правильность строк
    for ( int i = 0; i < count_lines - 1; i++){
        for (int j = 0; j < mx_strlen(lines[i].island1); j++) {
            if (mx_isalpha(lines[i].island1[j]) != true) {
                err_invalid_line_n(i + 2);
                for(int k = 0; k < count_lines - 1; k++){
                    mx_strdel(&lines[k].island1);
                    mx_strdel(&lines[k].island2);
                }
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
    t_island *islands = mx_create_node_island(lines[0].island1);
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
    //mx_strdel(&str);

//    t_island *tmp = islands;
//    while (tmp){
//        mx_printstr(tmp->island);
//        tmp = tmp->next;
//    }
    //==================================================================================================================

    //==================================================================================================================
    //проверка островов
    int real_count_of_islands = mx_list_size_islands(islands);
    if(real_count_of_islands != count_islands_file){
        mx_printerr("error: invalid count of islands");
        while(islands){
            mx_pop_back_island(&islands);
        }
        for(int i = 0; i < count_lines - 1; i++){
            mx_strdel(&lines[i].island1);
            mx_strdel(&lines[i].island2);
        }
    }
    //==================================================================================================================

    char *arr_islands[real_count_of_islands];
    for(int i = 0; i < real_count_of_islands; i++){
        arr_islands[i] = mx_strdup(islands->island);
        islands = islands->next;
    }
    while (islands){
        mx_pop_back_island(&islands);
    }

    int matrix[real_count_of_islands][real_count_of_islands];
    for (int i = 0; i < real_count_of_islands; i++){
        for(int j = 0; j < real_count_of_islands; j++){
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < count_lines - 1; i++){
        for(int j = 0; j < real_count_of_islands; j++){
            if(mx_strcmp(lines[i].island1, arr_islands[j]) == 0){
                for(int k = 0; k < real_count_of_islands; k++){
                    if(mx_strcmp(lines[i].island2, arr_islands[k]) == 0) {
                        matrix[j][k] = lines[i].path;
                        matrix[k][j] = lines[i].path;
                    }
                }
            }
        }
    }
    for (int i = 0; i < real_count_of_islands; i++){
        for (int j = 0; j < real_count_of_islands; j++){
            mx_printint(matrix[i][j]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
    for(int i = 0; i < real_count_of_islands; i++){
        Dijkstra(i ,real_count_of_islands, matrix);
    }
}

void Dijkstra(int st, int count_islands, int GR[count_islands][count_islands]) {
    int distance[count_islands];
    int count;
    int index;
    int i;
    int u;
    int m = st + 1;
    bool visited[count_islands];
    for (i = 0; i < count_islands; i++) {
        distance[i] = 2147483647;
        visited[i] = false;
    }
    distance[st] = 0;
    for (count = 0; count < count_islands - 1; count++) {
        int min = 2147483647;
        for (i = 0; i < count_islands; i++)
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                index = i;
            }
        u = index;
        visited[u] = true;
        for (i = 0; i < count_islands; i++)
            if (!visited[i] && GR[u][i] && distance[u] != 2147483647 &&
                distance[u] + GR[u][i] < distance[i])
                distance[i] = distance[u] + GR[u][i];
    }
    mx_printstr("Стоимость пути из начальной вершины до остальных:\t\n");
    for (i = 0; i < count_islands; i++) {
        if (distance[i] != 2147483647) {
            mx_printint(m);
            mx_printstr(" > ");
            mx_printint(i + 1);
            mx_printstr(" = ");
            mx_printint(distance[i]);
            mx_printchar('\n');
        } else {
            mx_printint(m);
            mx_printstr(" > ");
            mx_printint(i + 1);
            mx_printstr(" = ");
            mx_printstr("маршрут недоступен\n");
        }
    }
}



