#include <stdio.h>
#define NUMBER_OF_STUDENTS 5

int ask_number(int *target_ptr, int variable_number);
int show_result(int sum, float average);
int calculate_sum(int *numbers, int length);
float calculate_average(int *numbers, int length);


int main(void) {
    int score_array[NUMBER_OF_STUDENTS];
    int sum;
    float average;

    for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
        ask_number(&score_array[i], i);
    }

    sum = calculate_sum(score_array, NUMBER_OF_STUDENTS);
    average = calculate_average(score_array, NUMBER_OF_STUDENTS);

    show_result(sum, average);

    return 0;
}


int ask_number(int *target_ptr, int variable_number) {
    printf("Please input number to calculate sum and average %d: ", variable_number + 1);
    scanf("%d", target_ptr);

    return 0;
}


int show_result(int sum, float average) {
    printf("SUM: %d pt(s).\nAVG: %.1f pt(s).\n", sum, average);

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
