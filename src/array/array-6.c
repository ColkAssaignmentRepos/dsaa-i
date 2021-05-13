//
// Created by Manaki ITO on 2021/05/13.
//
#include <stdio.h>
#include <math.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define blank() {printf("\n");}
#define COEFFICIENTS {2, 1, 1, 1, 1};
#define INTERCEPTS {3, 7, 5, 8, 1};


int main() {
    int coefficients[] = COEFFICIENTS;
    int intercepts[] = INTERCEPTS;
    int term_number = sizeof(coefficients) / sizeof(int);

    long long int user_input_x;
    long long int result = 1;

    printf("Enter a number you want to input (n): ");
    scanf("%lld", &user_input_x);

    for (int i = 0; i < term_number; i++) {
        result *= coefficients[i] * user_input_x;
        result += intercepts[i];
    }

    blank();
    print_green("Calculated!");
    print_green("Result: %lld", result);

    return 0;
}
