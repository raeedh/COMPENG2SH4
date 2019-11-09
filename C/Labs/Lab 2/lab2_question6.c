#include <stdio.h>
#define k 3

void efficient(const int source[], int val[], int pos[], int size);
void reconstruct(int source[], int m, const int val[], const int pos[], int n);

int main() {

    /* int testsource_eff[] = {0, 0, 23, 0, -7, 0, 0, 48};
    int val_test_eff[k] = {0};
    int pos_test_eff[k] = {0}; */

    // efficient(testsource, val_test_eff, pos_test_eff, 8);

    /* Print val and pos for efficient
    int j;
    for (j = 0; j < k; j++) {
        printf("%d ", val_test[j]);
    }
    printf("\n");
    for (j = 0; j < k; j++) {
        printf("%d ", pos_test[j]);
    */

    int testsource_rec[8] = {0};
    int val_test_rec[] = {23, -7, 48};
    int pos_test_rec[] = {2, 4, 7};
    reconstruct(testsource_rec, 8, val_test_rec, pos_test_rec, 3);

    // Print vector for reconstruct
    int a;
    for (a = 0; a < 8; a++) {
        printf("%d ", testsource_rec[a]);
    }

    return 0;
}

void efficient(const int source[], int val[], int pos[], int size) {
    int val_position = 0, pos_position = 0, i;
    for (i = 0; i < size; i++) {
        if (source[i] != 0) {
            val[val_position] = source[i];
            val_position++;
            pos[pos_position] = i;
            pos_position++;
        }
    }
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n) {
    int val_position = 0, pos_position = 0, i;
    for (i = 0; i < m; i++) {
        if (i == pos[pos_position]) {
            source[i] = val[val_position];
            val_position++; pos_position++;
        }
        else {
            source[i] = 0;
        }
    } 
}