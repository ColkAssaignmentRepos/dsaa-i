//
// Created by Manaki ITO on 2021/05/07.
//
#include <stdio.h>
#include <stdlib.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define blank() {printf("\n");}

float standard_deviation(int *array, int length);


int main() {
    int user_input_length = -1;
    int *input_array = NULL;
    float avg = 0;

    printf("Enter a number you want to input (n): ");
    scanf("%d", &user_input_length);

    if (user_input_length <= 0) {
        print_error("Error: Expected a number larger than 0, but got \"%d\".", user_input_length);
        fatal(1, "Aborting");
    }

    input_array = (int *) malloc(sizeof(int) * user_input_length);
    if (input_array == NULL) {
        print_error("Error: Unexpected error has occurred. Failed to allocate array.");
    }

    blank();
    printf("Input numbers:\n");

    for (int i = 0; i < user_input_length; i++) {
        fflush(stdin);
        scanf("%d", &input_array[i]);
    }

    avg = average(input_array, user_input_length);

    blank();
    print_green("Calculated!");
    print_green("Average: %.2f", avg);

    return 0;
}


float standard_deviation(int *array, int length) {
    int sum = 0;
    float result;

    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    result = (float)sum / (float)length;
    return result;
}
