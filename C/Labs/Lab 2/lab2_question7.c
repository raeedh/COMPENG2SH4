#include <stdio.h>

#define eff_size_v1
#define eff_size_v2
#define eff_size_v3
#define sumNonZero 4

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2);

int main() {
    int v1[] = {5, 10, 15}, p1[] = {1, 2, 5}, v2[] = {-10, 7, -10, -3}, p2[] = {2, 5, 6, 8}, v3[sumNonZero] = {0}, p3[sumNonZero] = {0};
    addEff(v1, v2, v3, p1, p2, p3, sizeof(v1) / sizeof(v1[0]), sizeof(v2) / sizeof(v2[0]));

    
    for (int test = 0; test < sumNonZero; test++) {
        printf("%d ", v3[test]);
    }
    
    
    return 0;
}

void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2) {
    int k3 = k1 + k2, i, j, k, temp, flag = 0;
    
    // Gets k3
    for (i = 0; i < k1; i++) {
        for (j = 0; j < k2; j++) {
            if (pos1[i] == pos2[j]) {
                k3--;
                if (val1[i] + val2[j] == 0) {
                    k3--;
                }     
            }
        }
    }
    
    // Gets pos3 array
    k = 0;
    while (k < k3) {
        for (i = 0; i < k1; i++) {
            for (j = 0; j < k2; j++) {
                if (pos1[i] == pos2[j]) {
                    if (val1[i] + val2[j] == 0) {
                        flag++;
                    }
                }
            }
            if (flag == 0) {
                pos3[k] = pos1[i];
                k++;
            }
            flag = 0;
        }
        
        for (i = 0; i < k2; i++) {
            for (j = 0; j < k1; j++) {
                if (pos1[j] == pos2[i]) {
                    flag++;
                }
            }
            if (flag == 0) {
            pos3[k] = pos2[i];
            k++;
            }
            flag = 0;
        }
    }

    // Sorts pos3 array
    for (i = 0; i < k3; i++) {
        for (j = i + 1; j < k3; j++) {
            if (pos3[i] > pos3[j]) {
                temp = pos3[i];
                pos3[i] = pos3[j];
                pos3[j] = temp;
            }
        }
    } 

    // Gets val3 array
    for (i = 0; i < k3; i++) {
        for (j = 0; j < k1; j++) {
            if (pos3[i] == pos1[j]) {
                val3[i] += val1[j];
            }
        }
        for (j = 0; j < k2; j++) {
            if (pos3[i] == pos2[j]) {
                val3[i] += val2[j];
            }
        }
    }
}
