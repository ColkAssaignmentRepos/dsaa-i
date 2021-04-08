//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define NUMBERS_LENGTH 3

int ask_natural_number(int *target_ptr, char *variable_name);
int how_many_factors(int n);


int main() {
    int n;
    int number_of_factors;

    if (ask_natural_number(&n, "n") != 0) {
        printf("\x1b[41m");
        printf("Error! Expected only a natural number, but got negative integer.\n");

        return -1;
    }

    number_of_factors = how_many_factors(n);

    printf("Calculated!\nThe result is: %d\n", number_of_factors);

    return 0;
}


int ask_natural_number(int *target_ptr, char *variable_name) {
    printf("Please input number to calculate average %c: ", variable_name[0]);
    scanf("%d", target_ptr);

    if (*target_ptr < 0) {
        return -1;
    }

    return 0;
}


int how_many_factors(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            result += 1;
        }
    }

    return result;
}
