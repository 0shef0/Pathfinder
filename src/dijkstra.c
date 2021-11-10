#include "../inc/pathfinder.h"

void Dijkstra(int st, int count_islands, int GR[count_islands][count_islands], char *islands[count_islands]) {
    int distance[count_islands];
    int count;
    int index;
    int i;
    int u;
    int m = st + 1;
    int indexes[count_islands];
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
        indexes[count + 1] = index;
        for (i = 0; i < count_islands; i++)
            if (!visited[i] && GR[u][i] && distance[u] != 2147483647 &&
                distance[u] + GR[u][i] < distance[i]) {
                distance[i] = distance[u] + GR[u][i];
            }
    }
    mx_printstr("Стоимость пути из начальной вершины до остальных:\t\n");
    for (i = 0; i < count_islands; i++) {
        if (i > st) {
            if (distance[i] != 2147483647) {
                mx_printstr(islands[st]);
                for(int j = 0; indexes[j] != st; j++){
                    mx_printstr(" -> ");
                    mx_printstr(islands[indexes[j]]);
                }
                mx_printchar('\n');
                mx_printstr(islands[st]);
                mx_printstr(" > ");
                mx_printstr(islands[i]);
                mx_printstr(" = ");
                mx_printint(distance[i]);
                mx_printchar('\n');
            } else {
                mx_printint(m);
                mx_printstr(" > ");
                mx_printstr(islands[i]);
                mx_printstr(" = ");
                mx_printstr("маршрут недоступен\n");
            }
        }
    }
}
