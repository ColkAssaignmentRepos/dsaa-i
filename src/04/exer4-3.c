#include <stdio.h>
#include <string.h>
#define NUMBER_OF_STUDENTS 3
#define NUMBER_OF_SUBJECTS 5
#define SUBJECT_NAMES {"英\0", "数\0", "国\0", "社\0", "理\0"}
#define LENGTH_OF_SINGLE_ELEMENT 4

int ask_number(int *target_ptr, int number_of_student, char *subject_name_ptr);
int show_result(int *score_array_ptr);
int calculate_sum(int *numbers, int length);
float calculate_average(int *numbers, int length);


int main(void) {
    int score_array[NUMBER_OF_STUDENTS][NUMBER_OF_SUBJECTS];
    char subject_names[NUMBER_OF_SUBJECTS][LENGTH_OF_SINGLE_ELEMENT] = SUBJECT_NAMES;

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {

        for (int j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            ask_number(&score_array[i][j], i + 1, &subject_names[j][0]);
        }

    }

    show_result(*score_array);

    return 0;
}


int ask_number(int *target_ptr, int number_of_student, char *subject_name_ptr) {
    printf("How much did the student No. %d score on %s: ", number_of_student, subject_name_ptr);
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

    printf("平均点");
    printf("\n");

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        printf("%d番    ", i + 1);

        for (int j = 0; j < NUMBER_OF_SUBJECTS; j++) {
            printf("%2d    ", score_array[i][j]);
        }

        printf("%.1f", calculate_average(&score_array[i][0], NUMBER_OF_SUBJECTS));

        printf("\n");
    }

    printf("平均点 ");

    for (int i = 1; i < NUMBER_OF_SUBJECTS + 1; i++) {
        int sum = 0;

        for (int j = 1; j < NUMBER_OF_STUDENTS + 1; j++) {
            sum += score_array_ptr[(i * j) - 1];
        }


        printf("%.1f  ", (float)sum / (float)NUMBER_OF_STUDENTS);

    }

    printf("\n");

    return 0;
}


int calculate_sum(int *numbers, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum = sum + numbers[i];
    }

    return sum;
}


float calculate_average(int *numbers, int length) {
    float average;
    int sum = calculate_sum(numbers, length);

    average = (float)sum / (float)length;

    return average;
}
