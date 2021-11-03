#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    if (!head){
        return;
    }
    t_list *tmp = *head;
    while (tmp) {
        if (tmp->next != NULL && tmp->next->next != NULL){
            tmp = tmp->next;
        }
        else if (tmp->next != NULL) {
            free(tmp->next);
            tmp->next = NULL;
            break;
        } else {
            free(*head);
            *head = NULL;
            break;
        }
    }
}
