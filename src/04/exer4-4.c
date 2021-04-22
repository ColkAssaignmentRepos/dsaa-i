#include <stdio.h>
#define N 10

int recurrence(int n);


int main(void) {
    int result = recurrence(N);

    printf("Result: %d\n", result);

    return 0;
}


int recurrence(int n) {
    if (n == 0) {
        printf("Returned with %d\n", 0);
        return 0;
    }

    if (n == 1) {
        printf("Returned with %d\n", 1);
        return 1;
    }

    if (n == 2) {
        printf("Returned with %d\n", 2);
        return 2;
    }

    x
}
