//
// Created by Manaki ITO on 2021/05/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define SCORE_FILE_NAME "score.txt"
#define CLASS_WIDTH 10
#define CLASS_LENGTH 11

void pictograph(int *array, int length);
void show_pictograph(int classified[]);
void classify_into_classes(int *target, int length, int *result);
void initialize_array(int *target, int length);


int main() {
    int *input_array = NULL;
    FILE *score_file_ptr;

    score_file_ptr = fopen(SCORE_FILE_NAME, "r");
    if (score_file_ptr == NULL) {
        print_error("Error: Unexpected error has occurred. Failed to open the file \"%s\"", SCORE_FILE_NAME);
        fatal(1, "Aborting");
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

    pictograph(input_array, row_count);

    return 0;
}


void pictograph(int *array, int length) {
    int classes_ptr[CLASS_LENGTH];

    classify_into_classes(array, length, classes_ptr);
    show_pictograph(classes_ptr);
}


void show_pictograph(int classified[]) {
    int current_class_starts_at = 0;

    for (int i = 0; i < CLASS_LENGTH; i++) {
        int current_class_ends_at = current_class_starts_at + (CLASS_WIDTH - 1);

        if (current_class_starts_at == CLASS_WIDTH * (CLASS_LENGTH - 1)) {
            printf("%3d     : ", current_class_starts_at);
        }
        else {
            printf("%2d - %2d : ", current_class_starts_at, current_class_ends_at);
        }

        printf("%d", classified[i]);
        printf("\n");

        current_class_starts_at = current_class_ends_at + 1;
    }
}


void classify_into_classes(int *target, int length, int *result) {
    initialize_array(result, CLASS_LENGTH);

    for (int i = 0; i < length; i++) {
        int class_number = (int)(target[i] / CLASS_WIDTH);

        if (class_number > CLASS_LENGTH) {
            print_error("Error: Expected a number \"%d\" or less, but found \"%d\" at line %d.",
                        ((CLASS_LENGTH-1) * CLASS_WIDTH), target[i], i+1);
            fatal(1, "Aborting");
        }

        result[class_number] += 1;
    }
}


void initialize_array(int *target, int length) {
    memset( target, 0, length * sizeof(target[0]) );
}
