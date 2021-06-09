//
// Edited by Manaki ITO on 2021/05/27.
//

#include<stdio.h>

#define SIZE 10


void display(int data[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main(void) {
    int i, j, tmp;
    int data[SIZE] = {9, 3, 5, 4, 1, 7, 2, 6, 0, 8};
    display(data);
    for (i = 0; i < SIZE - 1; i++) {
        for (j = SIZE - 1; j > i; j--) {
            if (data[j] < data[j - 1]) {
                tmp = data[j - 1];
                data[j - 1] = data[j];
                data[j] = tmp;
                display(data);
            }
        }
    }
    display(data);
    return (0);
}
