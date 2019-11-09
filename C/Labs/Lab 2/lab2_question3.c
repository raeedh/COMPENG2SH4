#include <stdio.h>

#define size 3

void diag_scan(int array[][size], int n);

int main() {
    int test_array[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    diag_scan(test_array, size);

    return 0;
}

void diag_scan(int array[][size], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", array[i-j][j]);
        }
    }
    
    for (j = 1; j < n; j++) {
        for (i = (n-1); i >= j; i--) {
            printf("%d ", array[i][j+(n-1-i)]);
        }
    } 
}