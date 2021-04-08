//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define LENGTH_OF_ONE_BLOCK 10
#define CHARACTER "*"
#define BLANK printf("\n")

int ask_number(int *target_ptr);
int print_one_line(int length, int current);
int print_asterisks(int length);


int main() {
    int a;
    int number_of_blocks;
    int current;

    ask_number(&a);

    number_of_blocks = a / LENGTH_OF_ONE_BLOCK;
    for (int i = 1; i < number_of_blocks + 1; i++) {
        current = i * LENGTH_OF_ONE_BLOCK;

        print_one_line(LENGTH_OF_ONE_BLOCK, current);
    }

    int remains = a - (LENGTH_OF_ONE_BLOCK * number_of_blocks);
    if (remains == 0) {
        return 0;
    }

    print_one_line(remains, current);

    return 0;
}

int ask_number(int *target_ptr) {
    printf("How many '*'s do you want to print? : ");
    scanf("%d", target_ptr);

    return 0;
}

int print_one_line(int length, int current) {
    printf("%4d: ", current);
    print_asterisks(length);

    return 0;
}

int print_asterisks(int length) {
    for (int i = 0; i < length; i++) {
        printf(CHARACTER);
    }
    BLANK;

    return 0;
}
