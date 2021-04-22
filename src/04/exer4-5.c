#include <stdio.h>
#include <string.h>
#define MATRIX_LENGTH 2
#define MATRIX_NAMES "ab"

int ask_number(int *target_ptr, int number_of_student, char *subject_name_ptr);
int ask_number(int *target_ptr, int x, int y, char matrix_name)
int show_result(int *score_array_ptr);


int main(void) {
    char matrix_names[] = MATRIX_NAMES;
    int matrix_a[MATRIX_LENGTH][MATRIX_LENGTH];
    int matrix_b[MATRIX_LENGTH][MATRIX_LENGTH];

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {

        for (int j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            ask_number(matrix_a[i][j], i + 1, j + 1, matrix_names[0]);
        }

    }

    return 0;
}


int ask_number(int *target_ptr, int x, int y, char matrix_name) {
    printf("Value of (%d, %d) in the matrix %s: ", x, y, &matrix_name);
    scanf("%d", target_ptr);

    return 0;
}


int show_result(int *score_array_ptr) {
    int score_array[NUMBER_OF_STUDENTS][NUMBER_OF_SUBJECTS];
    char subject_names[NUMBER_OF_SUBJECTS][LENGTH_OF_SINGLE_ELEMENT] = SUBJECT_NAMES;

    memcpy(score_array, score_array_ptr, sizeof(int) * NUMBER_OF_STUDENTS * NUMBER_OF_SUBJECTS);

    printf("\n");
    printf("=================================\n");
    printf("\n       ");

    for (int i = 0; i < NUMBER_OF_SUBJECTS; i++) {
        printf("%s    ", &subject_names[i][0]);
    }

    printf("\n");

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        printf("%d番    ", i + 1);

        for (int j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            printf("%2d    ", score_array[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}
