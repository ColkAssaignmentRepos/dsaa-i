//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define NUMBERS_LENGTH 3

int ask_number(int *target_ptr, char *variable_name);


int main() {
    int a, b, c;
    int number_of_equal_numbers;
    char variable_names[] = "abc";

    ask_number(&a, &variable_names[0]);
    ask_number(&b, &variable_names[1]);
    ask_number(&c, &variable_names[2]);

    int numbers[] = {a, b, c};

    return 0;
}


int ask_number(int *target_ptr, char *variable_name) {
    printf("Please input number to calculate average %c: ", variable_name[0]);
    scanf("%d", target_ptr);

    return 0;
}

int how_many_equal_numbers(int *target) {
    int result = 0;
    int length = NUMBERS_LENGTH;

    if (target[0] == target[1] || target[1] == target[2] || target[0] == target[2]) {
        result += 1;
    }

    return result;
}
