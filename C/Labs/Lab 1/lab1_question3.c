#include <stdio.h>

int main() {
    int input, digits, number = 1;
    while (number != 0) { // Ends if number is zero, number defined as 1 at beginning so loop runs at least once
        printf("Please input an integer (0 to end): ");
        scanf("%d", &input);
        
        if (input < 0) { // Multiplies by -1 if input is negative
            number = input * -1;
        }
        else { 
            number = input;
        }

        digits = 1; // Starts at 1 since loop ends when number is below 10 and doesn't increment digits in that case
        while (number > 10) {
            number = number / 10;
            digits++;
        }

        if (digits == 5) {
            printf("Your input is a five-digit integer: %d\n", input); // Prints input instead of number because number is modified
        }
    }
    printf("Thank you for using my software. Bye!");

    return 0;
}