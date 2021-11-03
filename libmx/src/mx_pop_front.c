#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
    t_list *tmp = NULL;
    if (head == NULL || *head == NULL) {
        return;
    }
    if ((*head)->next != NULL) {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    } else {
        free(*head);
        *head = NULL;
    }
}
