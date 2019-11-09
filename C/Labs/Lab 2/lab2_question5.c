#include <stdio.h>

void string_copy(const char source[], char destination[], int n);

#define size 20

int main() {
    char testsource[] = 'test';
    char destarray[size] = {0};
    string_copy(testsource, destarray, size);

    int j = 0;
    for (j = 0; j < size; j++) {
        printf("%c", destarray[j]);
    }

    return 0;
}

void string_copy(const char source[], char destination[], int n) {
    int i;
    for (i = 0; i < (n - 1); i++) {
        if (source[i] == '\0') {
            break;
        }
        destination[i] = source[i];
    }
    destination[i] = '\0';
}