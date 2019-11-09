#include <stdio.h>


int main() {
    int sum=0, i;
    for (i=30; i<=1000; i++) { // For loop
        if(i%4 == 0) {
            sum = sum + i;
        }
    }
    printf("The sum of the integers using a for loop is %d.\n", sum);
    
    i=30;
    sum=0;
    while (i<=1000) { // While loop
        if(i%4 == 0) {
            sum = sum + i;
        }
        i++;
    }
    printf("The sum of the integers using a while loop is %d.\n", sum);

    i=30;
    sum=0;
    do { // Do while loop
        if(i%4 == 0) {
            sum = sum + i;
        }
        i++;
    } while (i<=1000);
    printf("The sum of the integers using a do while loop is %d.\n", sum);
    
    return 0;
}