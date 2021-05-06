//
// Created by Manaki ITO on 2021/05/06.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

#define error_log(message) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, message); fprintf(stderr, "\x1b[39m\n");}


int main(void) {
    int user_input;
    int number_of_bits;

    printf("Please input a natural number with the range (1~24): ");
    scanf("%d", &user_input);

    if (user_input > 24) {
        error_log("Error: The number that you inputted is too large.\n"
                  "Please input a natural number with the range (1~24).");
        error_log("Aborting");

        return 1;
    }

    if (user_input <= 0) {
        error_log("Error: The number that you inputted is too small.\n"
                  "Please input a natural number with the range (1~24).");
        error_log("Aborting");

        return 1;
    }

    number_of_bits = (int)ceil(pow(2, user_input));
    printf("The number of patterns of all the representable data with %d bit(s) is: %d\n", user_input, number_of_bits);

    return 0;
}
