//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define NUMBERS_LENGTH 3

int ask_number(int *target_ptr, char variable_name);
int how_many_equal_numbers_in(int target_array[], int array_length)
int is_sorted(int target_array[], int array_length);
int sort_int_array(int target_array[], int *sorted_array_ptr, int array_length);


int main() {
    int numbers[NUMBERS_LENGTH];
    char variable_names[NUMBERS_LENGTH] = "abc";
    int number_of_equal_numbers;

    for (int i = 0; i < NUMBERS_LENGTH; i++) {
        ask_number(&numbers[i], variable_names[i]);
    }

    number_of_equal_numbers = how_many_equal_numbers_in(numbers, NUMBERS_LENGTH);

    return 0;
}


int ask_number(int *target_ptr, char variable_name) {
    fflush(stdin);

    printf("Please input number to calculate how many is there equal numbers %c: ", variable_name);
    scanf("%d", target_ptr);

    return 0;
}


int how_many_equal_numbers_in(int target_array[], int array_length) {
    int sorted_array[array_length];
    int equals = 0;

    if (!(is_sorted(target_array, array_length))) {
        sort_int_array(target_array, sorted_array, array_length);
    }
}


int is_sorted(int target_array[], int array_length) {
    for (int i = 0; i < array_length - 1; i++) {
        if (target_array[i] > target_array[i+1]) {
            return 0;
        }
    }

    return 1;
}


int sort_int_array(int target_array[], int *sorted_array_ptr, int array_length) {
    int temp;
    int sorting[array_length];

    memcpy(sorting, target_array, sizeof(int) * NUMBERS_LENGTH);

    while ( !is_sorted(sorting, array_length) ) {
        for (int i = 0; i < array_length - 1; i++) {

            if (sorting[i] < sorting[i+1]) {
                temp = sorting[i];

                sorting[i] = sorting[i+1];
                sorting[i+1] = temp;
            }

        }
    }

    memcpy(sorted_array_ptr, sorting, sizeof(int) * NUMBERS_LENGTH);

    return 0;
}
