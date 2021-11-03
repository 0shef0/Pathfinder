#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size){
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            if (mx_strcmp(arr[j-1], arr[j]) > 0 ) {
                char *buf = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = buf;
                count++;
            }
        }
    }
    return count;
}
