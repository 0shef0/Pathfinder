#include "../inc/pathfinder.h"

void mx_pop_back_island(t_island **head) {
    if (!head){
        return;
    }
    t_island *tmp = *head;
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
