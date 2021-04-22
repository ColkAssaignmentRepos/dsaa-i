#include <stdio.h>

#define error_log(message) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, message); fprintf(stderr, "\x1b[39m\n");}

int ask_number(int *target_ptr);
int validate_input(int target);
int is_prime_number(int target);
void show_result(int number, int result);


int main(void) {
    int user_input;
    int is_prime_number_flag;

    ask_number(&user_input);
    if (!(validate_input(user_input))) {
        error_log("Error: Expected only natural numbers that is 2 or larger.");
        return 1;
    }

    is_prime_number_flag = is_prime_number(user_input);

    show_result(user_input, is_prime_number_flag);

    return 0;
}


int ask_number(int *target_ptr) {
    printf("Please input number to judge if it is a prime number or not: ");
    scanf("%d", target_ptr);

    return 0;
}


int validate_input(int target) {
    if (target >= 2) {
        return 1;
    }

    return 0;
}


int is_prime_number(int target) {
    for (int i = 2; i < target - 1; i++) {
        if (target % i == 0) {
            return 0;
        }
    }

    return 1;
}


void show_result(int number, int result) {
    if (!(result)) {
        printf("Result: %d is not a prime number.\n", number);
        return;
    }

    printf("Result: %d is a prime number.\n", number);
}
