#include <stdio.h>
#include <stdlib.h>

char **read_words(const char *input_filename, int *nPtr) {
    char** word_array;

    FILE *input_file = fopen(input_filename, "r");
    fscanf(input_file, "%d", nPtr);
    
    word_array = calloc(*nPtr, sizeof(char *));

    for (int i = 0; i < *nPtr; i++) {
        fscanf(input_file, "%ms", &word_array[i]);
    }

    fclose(input_file);

    return word_array;
}

int compare(char *string1, char *string2) {
    if (string1[0] > string2[0]) {
        return 1;
    }
    return 0;
}

void sort_words(char **array_strings, int *nPtr) {
    char *key;
    int j = 0;
    for (int i = 1; i < *nPtr; i++) {
        key = array_strings[i];
        j = i -1;
        while (j >= 0 && (compare(array_strings[j],key) == 1)) {
            array_strings[j + 1] = array_strings[j];
            j = j - 1;
        }
        array_strings[j+1] = key; 
    }   
}

void sort2_words(char **array_strings, int *nPtr) {
// incomplete
}

void output_words(char **array_strings, int *nPtr) {
    for (int i = 0; i < *nPtr; i++) {
        printf("%s", array_strings[i]);
    }
}

void main() {
    int *word_number;
    char **string_array = read_words("bonus_inputfile.txt", word_number);
    // sort_words(string_array, word_number);
    // output_words(string_array, word_number);
}