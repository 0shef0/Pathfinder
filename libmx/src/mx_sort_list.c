#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (cmp == NULL || lst == NULL) {
        return lst;
    }
    t_list *temp = lst;
    int count = 0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    for (int i = 0; i < count; i++) {
        temp = lst;
        for (int j = 0; j < count - 1; j++) {
            if (cmp(temp->data, temp->next->data)) {
                void *data = temp->data;
                temp->data = temp->next->data;
                temp->next->data = data;
            }
            temp = temp->next;
        }
    }
    return lst;
}
