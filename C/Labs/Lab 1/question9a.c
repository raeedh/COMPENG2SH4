#include <stdio.h>

int main() {
    int n = 0, previous = 0, digits, counter = 0, i = 0;
    FILE *input_file = fopen("inputfile1.txt", "r");
    FILE *output_file = fopen("outputfile1.txt", "w");
    fscanf(input_file, "%d", &digits);
    while (i < digits) {
        fscanf(input_file,"%d",&n);
        if (n == 0 && previous == 0) { // Checks all cases of sequential values
            counter++;
            previous = n;
        }
        else if (n == 0 && previous == 1) { // Prints and resets counter when values change
            previous = n;
            fprintf(output_file, "%d ", counter);
            counter = 1; // Counter resets to 1 because a run contains at least 1 bit 
        }
        else if (n == 1 && previous == 0) {
            previous = n;
            fprintf(output_file, "%d ", counter);
            counter = 1;
        }
        else {
            counter++;
            previous = n;   
        }
        i++;
    }
    fprintf(output_file,"%d\n", counter);
    fclose(input_file);
    fclose(output_file);
    return 0;        
}