#include "../inc/libmx.h"

void mx_printint(int n) {
    int flag = 0;
    int zero = 0;
    if ( n == 0 ) {
        mx_printchar('0');
        return;
    }
    int k = 0;
    if (n < 0){
        mx_printchar('-');
        if ( ( n % 10 ) != 0 ) {
            n += 1;
        } else {
            zero = 1;
        }
        n *= -1;
        flag = 1;
    }
    int n_buf = n;
    if ( n == 0 ){
        k++;
    }

    while (n != 0) {
        n /= 10;
        k++;
    }

    int arr[k];
    for (int i = 0 ; i < k ; i++) {
        arr[i] = n_buf % 10;
        n_buf /= 10;
    }

    for (int i = k-1; i >= 0; i--) {
        if ( flag == 1 && i == 0 && arr[i] != 9 && zero == 0) {
            arr[i] += 1;
        }
        mx_printchar(arr[i] + 48);
    }
}
