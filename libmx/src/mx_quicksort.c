#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    if ( left < right ) {
        int l = left;
        int r = right;
        char *mid = arr[(l + r) / 2];

        do {
            while (mx_strlen(arr[l]) < mx_strlen(mid)) {
                l++;
            }
            while (mx_strlen(arr[r]) > mx_strlen(mid)) {
                r--;
            }
            if (l <= r) {
                char *tmp = arr[l];
                arr[l] = arr[r];
                arr[r] = tmp;
                l++;
                r--;
                count++;
            }
        } while (l <= r);
            mx_quicksort(arr, left, r);
            mx_quicksort(arr, l, right);
    }
    return count;
}
