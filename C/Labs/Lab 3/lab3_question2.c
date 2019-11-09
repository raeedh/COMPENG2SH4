#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int student_id;
    char first_name[15];
    char last_name[15];
    int project1_grade;
    int project2_grade;
    float final_grade;
} student;

student **create_class_list(char *filename, int *sizePtr) {
    student** p; 
    int i;
    FILE *name_file = fopen(filename, "r");

    fscanf(name_file, "%d", sizePtr);
    p = malloc(*sizePtr * sizeof(student *)); // Allocates memory for array of student pointers
    for (i = 0; i < *sizePtr; i++) {
        student *s = calloc(1, sizeof(student)); // Creates and allocates memory for each student pointer, initializies values to 0
        fscanf(name_file, "%d", &s -> student_id);
        fscanf(name_file, "%s", s -> first_name);
        fscanf(name_file, "%s", s -> last_name);
        p[i] = s; // Assigns element in array to student pointer
    }

    fclose(name_file);
    return p;
}

int find(int idNo, student **list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (idNo == list[i] -> student_id) { // Loops through list and checks if any elements match the inputted student number
            return i; // Returns index if a match is found
        }
    }
    return -1; // Returns -1 if no match is found
}

void input_grades(char *filename, student **list, int size) {
    int id = 0, student_pos = 0;
    FILE *grade_file = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        fscanf(grade_file, "%d", &id); // Scans student ID
        student_pos = find(id, list, size);
        fscanf(grade_file, "%d", &(list[student_pos] -> project1_grade)); // Saves grade to project1_grade after finding index of student
        fscanf(grade_file, "%d", &(list[student_pos] -> project2_grade)); // Saves grade to project2_grade after finding index of student
    }
    fclose(grade_file);
}

void compute_final_course_grades(student **list, int size) {
    for (int i = 0; i < size; i++) {
        list[i] -> final_grade = ((float)(list[i] -> project1_grade) + (float)(list[i] -> project2_grade)) / 2; // Saves arithmetic average to final_grade
    }
}

void output_final_course_grades(char *filename, student **list, int size) {
    FILE *final_grade_file = fopen(filename, "w");

    fprintf(final_grade_file, "%d\n", size); // Prints number of students at start
    for (int i = 0; i < size; i++) {
        fprintf(final_grade_file, "%d %f\n", list[i] -> student_id, list[i] -> final_grade); // Loops and prints each pair of student ID and final grade on individual lines
    }

    fclose(final_grade_file);
}

void print_list(student **list, int size) {
    for (int i = 0; i < size; i++) { // Loops and prints all the members of structure 
        printf("ID: %d, name: %s %s, project 1 grade: %d, project 2 grade: %d, final grade: %f\n", list[i] -> student_id, list[i] -> first_name, list[i] -> last_name, list[i] -> project1_grade, list[i] -> project2_grade, list[i] -> final_grade);
    }
}

void withdraw(int idNo, student **list, int *sizePtr) {
    int student_pos = find(idNo, list, *sizePtr);
    if (student_pos == -1) { // Checks if student is in list
        printf("This student was not found. \n");
    }
    else {
        (*sizePtr)--; // Decreases size of list by 1
        free(list[student_pos]); // Frees allocated memory for student
        for (student_pos; student_pos < *sizePtr; student_pos++) { 
            list[student_pos] = list[student_pos + 1]; // Loops and copies next student to current index
        }
    }
}

void destroy_list(student **list, int *sizePtr) {
    for (int i = 0; i < *sizePtr; i++) {
        free(list[i]);
    }
    free(list);
    *sizePtr = 0;
}

int main() {
    int size_of_list;
    int withdraw_id;
    student** student_list;
    student_list = create_class_list("inputfile.txt", &size_of_list);
    
    printf("The created class list:\n");
    print_list(student_list, size_of_list);
    printf("\n");
    
    input_grades("grades_file.txt", student_list, size_of_list);
    printf("The list after inputting grades:\n");
    print_list(student_list, size_of_list);
    printf("\n");
    
    compute_final_course_grades(student_list, size_of_list);
    printf("The list after computing final grades:\n");
    print_list(student_list, size_of_list);
    printf("\n");
    
    output_final_course_grades("final_grades.txt", student_list, size_of_list);
    printf("The final grades have been outputted in file 'final_grades.txt'.\n");
    printf("\n");
    
    printf("Please input a student ID not in the list to withdraw: ");
    scanf("%d", &withdraw_id);
    withdraw(withdraw_id, student_list, &size_of_list);
    printf("The list after failing to withdraw a student:\n");
    print_list(student_list, size_of_list);
    printf("\n");
    
    printf("Please input a student ID in the list to withdraw: ");
    scanf("%d", &withdraw_id);
    withdraw(withdraw_id, student_list, &size_of_list);
    printf("The list after successfully withdrawing a student:\n");
    print_list(student_list, size_of_list);
    printf("\n");
    
    printf("Please input a student ID in the list to withdraw: ");
    scanf("%d", &withdraw_id);
    withdraw(withdraw_id, student_list, &size_of_list);
    printf("The list after successfully withdrawing a student:\n");
    print_list(student_list, size_of_list);
    printf("\n");

    destroy_list(student_list, &size_of_list);
    printf("The list after it has been destroyed.\n");
    print_list(student_list, size_of_list);
    printf("\n");
    printf("The size of the list after destroying the list is %d.", size_of_list);
}