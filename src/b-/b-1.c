#include <stdio.h>

#define SIZE 5


void display(int data[]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}


int main(void) {
    int i, j, tmp;
    int data[SIZE] = {9, 3, 5, 4, 1};

    display(data);
    printf("-----------\n");

    for (i = SIZE - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (data[j + 1] < data[j]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
        display(data);
    }

    return 0;
}
