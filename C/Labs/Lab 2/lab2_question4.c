#include <stdio.h>

void letter_freq(const char word[], int freq []);

int main() {
    int freqarray[26] = {0};
    letter_freq("word", freqarray);
    
    return 0;
}

void letter_freq(const char word[], int freq []) {
    int i = 0, j, ascii;
    while (word[i] != '\0') {
        ascii = word[i];
        if (ascii > 96) {
            ascii = ascii - 97;
        }
        else {
            ascii = ascii - 65;
        }
        freq[ascii]++;
        i++;
    }
    for (j = 0; j < 26; j++) {
        printf("The count of '%c' and '%c' is %d\n", j+65, j+97, freq[j]);
    }
}