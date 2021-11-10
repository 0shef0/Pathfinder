#include "../inc/pathfinder.h"

void Dijkstra(int st, int count_islands, int GR[count_islands][count_islands], char *islands[count_islands]) {
    //char *sum_of_routes[count_islands];
    int v[count_islands]; // посещенные вершины
    int temp, minindex, min;
    int begin_index = st;
    int d[count_islands];
    for (int i = 0; i<count_islands; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    // Шаг алгоритма
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<count_islands; i++)
        { // Если вершину ещё не обошли и вес меньше min
            if ((v[i] == 1) && (d[i]<min))
            { // Переприсваиваем значения
                min = d[i];
                minindex = i;
            }
        }
        // Добавляем найденный минимальный вес
        // к текущему весу вершины
        // и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
            for (int i = 0; i<count_islands; i++)
            {
                if (GR[minindex][i] > 0)
                {
                    temp = min + GR[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);
    for (int i = count_islands - 1; i >= 0; i --) {
        int ver[count_islands]; // массив посещенных вершин
        int end = count_islands - i - 1; // индекс конечной вершины = 5 - 1
        ver[0] = end + 1; // начальный элемент - конечная вершина
        int k = 1; // индекс предыдущей вершины
        int weight = d[end]; // вес конечной вершины

        while (end != begin_index) // пока не дошли до начальной вершины
        {
            for (int j = count_islands - 1; j >= 0; j--) {// просматриваем все вершины
                if (GR[j][end] != 0)   // если связь есть
                {
                    int temp = weight - GR[j][end]; // определяем вес пути из предыдущей вершины
                    if (temp == d[j]) // если вес совпал с рассчитанным
                    {                 // значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес
                        end = j;       // сохраняем предыдущую вершину
                        ver[k] = j + 1; // и записываем ее в массив
                        k++;
                    }
                }
            }
        }
        // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
            mx_printstr("\nВывод кратчайшего пути\n");
            for (int m = k - 1; m >= 0; m--) {
                    mx_printstr(islands[ver[m] - 1]);
                    mx_printstr(" -> ");
            }
            mx_printchar('\n');
            mx_printint(d[count_islands - i - 1]);
    }

}
