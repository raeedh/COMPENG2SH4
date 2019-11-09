#include <stdio.h>

int main() {
    int m, num, i, sum;
    printf("Please input an integer m (m > 1): ");
    scanf("%d", &m);
    for (num=1; num<=m; num++) {
        sum = 0;
        for (i=1; i<num; i++) {
            if (num % i == 0) {
            sum = sum + i;
            }
        }
        if (num == sum) {
            printf("%d is a perfect number.\n", num);
        }
    }
    return 0;
}