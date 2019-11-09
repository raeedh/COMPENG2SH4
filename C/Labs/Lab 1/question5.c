#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double pi = 0;

    printf("Please input the value of n: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        pi = pi + ((pow(-1, (i + 1))) * (4.0 / ((2.0 * i) - 1.0)));
    }

    printf("The value of pi is: %lf", pi);

    return 0;
}