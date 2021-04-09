//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define LENGTH_OF_SIDE 9

int print_header(int length_of_side);
int print_one_line(int current_line, int length_of_side);


int main() {
    print_header(LENGTH_OF_SIDE);

    for (int i = 1; i <= LENGTH_OF_SIDE; i++) {
        print_one_line(i, LENGTH_OF_SIDE);
    }

    return 0;
}


int print_header(int length_of_side) {
    printf("|___|");

    for (int i = 1; i <= length_of_side; i++) {
        printf("%3d|", i);
    }

    printf("\n");
    return 0;
}


int print_one_line(int current_line, int length_of_side) {
    int product;
    printf("|%3d|", current_line);

    for (int i = 1; i <= length_of_side; i++) {
        product = current_line * i;
        printf("%3d|", product);
    }

    printf("\n");

    return 0;
}
