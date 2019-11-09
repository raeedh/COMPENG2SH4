#include <stdio.h>
#include <math.h>
#define N 3

int is_diag_dom(int mat[][N]);

int main() {
    int mat[N][N] = {-4, 2, 1, 1, 6, 2, 1, -2, 5};
    printf("%d", is_diag_dom(mat));
        
    return 0;
}

int is_diag_dom(int mat[][N]) {
    int i, j, sum;
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum = sum + abs(mat[i][j]);
        }
        sum = sum - abs(mat[i][i]);
        if (abs(mat[i][i]) <= sum) {
            return 0;
        }
    }
    return 1;
}