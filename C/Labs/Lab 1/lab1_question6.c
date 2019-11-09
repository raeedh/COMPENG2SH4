#include <stdio.h>
#include <math.h>

int main() {
    int side1, side2, hypotsqrd, h, counter = 0;

    for (side1 = 1; side1 <= 400; side1++) {        
            for (side2 = side1; side2 <= 400; side2++) {   
                hypotsqrd = pow(side1,2)+pow(side2,2); // Gets value of the hypotenuse squared

                for (h = 1  ; h <= 400; h++) {   
                    if (hypotsqrd == pow(h,2)) { // Determine if hypotenuse is an integer by comparing its square to square of h, which is an integer.
                        printf("%d, %d, %d \n", side1, side2, h);
                        counter++;
                }
            }
        }
    }
    printf("The total number of triples is %d.", counter);
    return 0;    
}