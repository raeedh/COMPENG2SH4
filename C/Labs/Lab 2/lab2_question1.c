#include <stdio.h>
#include <math.h>

#define print_size 5
#define add_n 5
#define scalprod_n 3
#define norm2_size 3

void print_vector(double array[], int size);
void add_vectors(double vector1[], double vector2[], double vector3[], int n);
double scalar_prod(double vector1[], double vector2[], int n);
double norm2(double vector1[], int size);

int main() {
    /*
    double test_print_array[print_size] = {1, 2, 3, 4, 5};
    print_vector(test_print_array, print_size);

    double test_add_v1[add_n] = {0};
    double test_add_v2[add_n] = {0};
    double test_add_v3[add_n] = {0};
    add_vectors(test_add_v1, test_add_v2, test_add_v3, add_n);

    double test_scalprod_v1[scalprod_n] = {1, 2, 3};
    double test_scalprod_v2[scalprod_n] = {4, 5, 6};
    printf("The scalar product is %lf\n", scalar_prod(test_scalprod_v1, test_scalprod_v2, scalprod_n));
    */
    double norm2_v1[] = {1, 2, 3};
    printf("The L2 norm of the vector is %lf\n", norm2(norm2_v1, norm2_size));

    return 0;
}

void print_vector(double array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%lf, ", array[i]);
    }
}

void add_vectors(double vector1[], double vector2[], double vector3[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        vector3[i] = vector1[i] + vector2[i];
    }
}

double scalar_prod(double vector1[], double vector2[], int n) {
    double scalar_prod = 0;
    int i;
    for (i = 0; i < n; i++) {
        scalar_prod = scalar_prod + (vector1[i] * vector2[i]);
    }
    return scalar_prod;
}

double norm2(double vector1[], int size) {
    double l2norm = 0;
    l2norm = sqrt(scalar_prod(vector1, vector1, size));
    return l2norm;
}