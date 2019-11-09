#include <stdio.h>

int main() {
    int smallest, n, input, i;

    printf("Please select the number of inputs (n): \n");
    scanf("%d", &n);

    while (n<=0) {
        printf("This is an invalid input, please select a positive integer: \n");
        scanf("%d",&n);
    }
    printf("Please input an integer: \n");
    scanf("%d",&smallest);

    for (i=1; i<n; i++){
        printf("Please input an integer: \n");
        scanf("%d",&input);

        if (input < smallest) {
            smallest = input;
        }
    }
    printf("The smallest integer is %d.", smallest);
    return 0;
}