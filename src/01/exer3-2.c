//
// Created by Manaki ITO on 2021/04/08.
//
#include <stdio.h>
#include <string.h>
#define LENGTH_OF_ONE_BLOCK 10
#define CHARACTER "*"

int ask_number(int *target_ptr, char *variable_name);
int print_asterisk(int length);
int print_one_line(int length, int current);


int main() {
    int a;
    int remains;
    int number_of_blocks;
    int current;

    ask_number(&a, "a");

    number_of_blocks = a / LENGTH_OF_ONE_BLOCK;
    for (int i = 1; i < number_of_blocks + 1; i++) {
        current = i * LENGTH_OF_ONE_BLOCK;

        print_one_line(LENGTH_OF_ONE_BLOCK, current);
    }

    remains = a - (LENGTH_OF_ONE_BLOCK * number_of_blocks);
    if (remains == 0) {
        return 0;
    }

    print_one_line(remains, current);

    return 0;
}

int ask_number(int *target_ptr, char *variable_name) {
    printf("How many '*'s do you want to print? : ");
    scanf("%d", target_ptr);

    return 0;
}

int print_one_line(int length, int current) {
    printf("%4d: ", current);
    print_asterisk(length);
    return 0;
}

int print_asterisk(int length) {
    for (int i = 0; i < length; i++) {
        printf(CHARACTER);
    }
    printf("\n");

    return 0;
}
