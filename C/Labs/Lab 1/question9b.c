#include <stdio.h>

int main() {
    int digits, n, i = 0, j, binary;
    FILE *input_file = fopen("inputfile2.txt", "r");
    FILE *output_file = fopen("outputfile2.txt", "w");
    
    fscanf(input_file, "%d", &digits);

    while (i < digits) {
        fscanf(input_file, "%d", &n);
        binary = i % 2; // Determines whether to print 0 or 1, starts with 0 as i begins at 0.
        for (j = 0; j < n; j++) {
            fprintf(output_file, "%d ", binary);
        }
    i++;
    }
}