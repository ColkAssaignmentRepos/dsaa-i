#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}
#define blank() {printf("\n");}

#define NUMBER_OF_ITEMS 100
#define RAND_MAX_RANGE 1000
#define NUMBER_OF_DIGITS 4


int main(void) {
    int array[NUMBER_OF_ITEMS];
    int tmp;

    time_t current_time = time(0);
    srand(current_time);

    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
        array[i] = rand() % RAND_MAX_RANGE + 1;
    }

    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {

        for (int j = i - 1; j >= 0; j--) {
            if (array[j] > array[j+1]) {
                tmp = array[j+1];

                array[j+1] = array[j];
                array[j] = tmp;
            }
            else {
                break;
            }

        }

    }

    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
        printf("%3d| %d ", i+1, array[i]);
        printf("\n");
    }

    return (0);
}
