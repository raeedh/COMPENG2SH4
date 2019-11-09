#include <stdio.h>

int main() {
    int num, reverse = 0;
    printf("Input an integer to reverse: ");
    scanf("%d", &num);
    while (num != 0) {
        reverse = reverse * 10; // Shifts digits in reverse to left
        reverse = reverse + (num % 10); // Adds last digit to reverse
        num = num / 10;
    }   
    printf("The reverse of the integer inputted is: %d", reverse);
    return 0;
}