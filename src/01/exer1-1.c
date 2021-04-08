//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define NUMBERS_LENGTH 3
#define BLANK printf("\n")

int ask_number(int *target_ptr, char variable_name);
int calculate_average(int *numbers, int length);


int main() {
    int a, b, c;
    double average;
    char variable_names[] = "abc";

    ask_number(&a, variable_names[0]);
    ask_number(&b, variable_names[1]);
    ask_number(&c, variable_names[2]);
    BLANK;

    int numbers[] = {a, b, c};
    average = calculate_average(numbers, NUMBERS_LENGTH);

    printf("Calculated!\nThe result is: %.2f\n", average);

    return 0;
}


int ask_number(int *target_ptr, char variable_name) {
    printf("Please input number to calculate average %c: ", variable_name);
    scanf("%d", target_ptr);

    return 0;
}


int calculate_average(int *numbers, int length) {
    int sum = 0;
    float average;

    for (int i = 0; i < length; i++) {
        sum = sum + numbers[i];
    }

    average = (float)sum / (float)length;

    return average;
}
