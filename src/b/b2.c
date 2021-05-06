//
// Created by Manaki ITO on 2021/05/06.
//
#include <stdio.h>
#include <string.h>
#include <math.h>

#define error_log(message) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, message); fprintf(stderr, "\x1b[39m\n");}


int main(void) {
    char bit[100];
    int i, d, len;
    int j = 0;
    int x = 0;

    printf("Please enter a 2-based number: ");
    scanf("%s", bit);

    len = strlen(bit);

    // __(ア)__
    for (i = len-1; i >= 0; i--) {
        if (bit[i] == '0') {
            d = 0;
        }
        else if (bit[i] == '1') {
            d = 1;
        }
        else {
            error_log("Error: Expected only '0 or '1', but got unexpected character.\n");
            error_log("Aborting");
            return(1);
        }

        // __(イ)__
        x = x + d * pow(2, j);
        j++;
    }

    printf("10-based number: %d\n", x);

    return 0;
}