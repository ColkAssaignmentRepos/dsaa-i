//
// Created by Manaki ITO on 2021/05/13.
//
#include <stdio.h>
#include <stdlib.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define blank() {printf("\n");}
#define SCORE_FILE_NAME "score.txt"

int max_in_array(int *array, int length);


int main() {
    int *input_array = NULL;
    int max_number = 0;
    FILE *score_file_ptr;

    score_file_ptr = fopen(SCORE_FILE_NAME, "r");
    if (score_file_ptr == NULL) {
        print_error("Error: Unexpected error has occurred. Failed to open the file \"%s\"", SCORE_FILE_NAME);
    }

    int current_integer;
    int row_count = 0;
    while(( fscanf(score_file_ptr, "%d", &current_integer)) != EOF ){
        if (row_count == 0) {
            input_array = (int *) malloc(sizeof(int));
        }
        else {
            input_array = (int *) realloc(input_array ,sizeof(int) * (row_count+1));
        }

        input_array[row_count] = current_integer;

        row_count++;
    }

    max_number = max_in_array(input_array, row_count);

    print_green("Calculated!");
    print_green("Max: %d", max_number);

    return 0;
}


int max_in_array(int *array, int length) {
    int current_max = array[0];

    for (int i = 0; i < length; i++) {
        if (array[i] > current_max) {
            current_max = array[i];
        }
    }

    return current_max;
}
