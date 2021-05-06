//
// Created by Manaki ITO on 2021/05/06.
//
#include <stdio.h>


int main(void) {
    int a[100];
    int b = 0, i, x;

    printf("Please enter a 10-based number: ");
    scanf("%d", &x);

    while (x > 0) {
        a[b] = x%2;

        // __(ア)__
        x = x>>1;

        b++;
    }

    printf("2-based number: ");

    // __(イ)__
    for (i = b-1; i >= 0; i--) {
        printf("%d", a[i]);
    }

    printf("\n");

    return 0;
}