#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strcat(const char const *str1, const char const *str2) { // Function prototype 
    int i, str3_pos = 0; // 
    char *str3 = NULL;
    int size_conc = strlen(str1) + strlen(str2) + 1; // Size of concatenated string = sizes of str1 and str2 + null-terminator
    str3 = calloc(size_conc, sizeof(char));
    for (i = 0; i < strlen(str1); i++) { // Loops through str1 and copies values to str3  
        str3[str3_pos] = str1[i];
        str3_pos++;
    }
    for (i = 0; i < strlen(str2); i++) { // Loops through str2 and copies values to str3
        str3[str3_pos] = str2[i];
        str3_pos++;
    }
    str3[str3_pos] = '\0'; // Adds null-terminator to end of string

    return str3;
}

void main() {
    int size_string1 = 0;
    int size_string2 = 0;
    char *string1;
    char *string2;

    /*
    // In case %ms does not work, this will ask for number of characters in string from user to allocate memory for array
    printf("Input the number of characters in the first string to concatenate: ");
    scanf("%d", &size_string1);
    string1 = calloc(size_string1, sizeof(char)); 
    */

    printf("Input the first string to concatenate: ");
    // Remember to remove & if not using %ms
    scanf("%ms", &string1); // Operator m causes scanf to dynamically allocates enough memory to hold the string    

    /*
    // In case %ms does not work, this will ask for number of characters in string from user to allocate memory for array
    printf("Input the number of characters in the second string to concatenate: ");
    scanf("%d", &size_string2);
    string2 = calloc(size_string1, sizeof(char));
    */

    printf("Input the second string to concatenate: ");
    // Remember to remove & if not using %ms
    scanf("%ms", &string2); // Operator m causes scanf to dynamically allocates enough memory to hold the string
    

    printf("%s\n", my_strcat(string1, string2));

    free(string1);
    free(string2);
}
