//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define NUMBERS_LENGTH 2
#define MESSAGE "%c: %lf\n"

int ask_number(double *target_ptr, char *variable_name);
int calculate_average(int *numbers, int length);
int print_double(double number, char name_of_variable);


int main() {
    double a, b;
    char variable_names[] = "ab";

    ask_number(&a, &variable_names[0]);
    ask_number(&b, &variable_names[1]);
    printf("\n");

    if (a >= b) {
        print_double(a, variable_names[0]);
        print_double(b, variable_names[1]);

        return 0;
    }

    print_double(b, variable_names[1]);
    print_double(a, variable_names[0]);

    return 0;
}


int ask_number(double *target_ptr, char *variable_name) {
    printf("Please input number '%c': ", variable_name[0]);
    scanf("%lf", target_ptr);

    return 0;
}

int print_double(double number, char name_of_variable) {
    printf(MESSAGE, name_of_variable, number);

    return 0;
}
