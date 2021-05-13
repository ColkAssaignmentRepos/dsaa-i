//
// Created by Manaki ITO on 2021/05/13.
//
#include <stdio.h>
#include <stdlib.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define blank() {printf("\n");}

int max_in_array(int *array, int length);


int main() {
    int user_input_length = -1;
    int *input_array = NULL;
    int max_number = 0;

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

    max_number = max_in_array(input_array, user_input_length);

    blank();
    print_green("Calculated!");
    print_green("Max: %d", max_number);

    return 0;
}


int max_in_array(int *array, int length) {
    int current_max = array[0];

    for (int i = 1; i < length; i++) {
        if (array[i] > current_max) {
            current_max = array[i];
        }
    }

    return current_max;
}
