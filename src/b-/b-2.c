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
    int data[SIZE] = {1, 2, 3, 4, 5};
    int swaps_num = 0;

    display(data);
    printf("-----------\n");

    for (i = SIZE - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (data[j + 1] < data[j]) {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                swaps_num++;
            }
        }

        if (swaps_num == 0) {
            printf("This array is already sorted!\n");
            break;
        }

        display(data);
    }

    return 0;
}
