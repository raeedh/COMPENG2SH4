#include <stdio.h>

int main() {
    float average;
    printf("Please input an average between 0-100: ");
    scanf("%f", &average);
    if (average>100 || average<0) {
        printf("The input is invalid.");
    }
    if (average>=90) {
        printf("4");
    }
    else if (average>=80) {
        printf("3");
    }
    else if (average>=70) {
        printf("2");
    }
    else if (average>=60) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}
