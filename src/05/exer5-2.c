#include <stdio.h>
#include <stdlib.h>

#define error_log(message) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, message); fprintf(stderr, "\x1b[39m\n");}

int ask_length(int *target_ptr);
int ask_number(float *target_ptr, int index);
int allocate_array_of_int_with_length(float *target_ptr, int length);
float max(float *target_ptr, int length);


int main(void) {
    int length_of_array;
    float *array;
    float max_value;

    ask_length(&length_of_array);
    allocate_array_of_int_with_length(array, length_of_array);

    for (int i = 0; i < length_of_array; i++) {
        ask_number(array + i, i);
    }

    max_value = max(array, length_of_array);

    printf("Result: The largest number is %f.\n", max_value);

    return 0;
}


int ask_length(int *target_ptr) {
    printf("How many numbers do you want to input: ");
    scanf("%d", target_ptr);

    return 0;
}


int ask_number(float *target_ptr, int index) {
    printf("%d: ", index);
    scanf("%f", target_ptr);

    return 0;
}


int allocate_array_of_int_with_length(float *target_ptr, int length) {
    target_ptr = (float *) malloc(sizeof(float) * length);

    return 0;
}


float max(float *target_ptr, int length) {
    float max_value;

    if (length < 1) {
        error_log("Unexpected Error: Array of size zero is unexpected.");
    }

    max_value = target_ptr[0];

    for (int i = 0; i < length; i++) {
        if (max_value < target_ptr[i]) {
            max_value = target_ptr[i];
        }
    }

    return max_value;
}
