#include <stdio.h>

#define M 11
#define N 6
#define MAX 9999


int main(void) {
    int i, j, p;
    int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40, MAX};
    int b[] = {6, 11, 25, 33, 35, MAX};
    int c[N + M]; // __(ア)__

    i = j = p = 0;
    while (i < M && j < N) { /* 配列のa,bのどちらもが終端になるまで繰り返す */
        if (a[i] <= b[j]) c[p++] = a[i++];
        else if (a[i] > b[j]) c[p++] = b[j++];

        if (i > 0) {
            if (a[i - 1] == MAX) for (; j < N; j++) c[p++] = b[j++]; /* 配列のaが終端に達していた場合、配列のbの残り部分を結合する */
        }

        if (j > 0) {
            if (b[j - 1] == MAX) for (; i < N; i++) c[p++] = a[i++]; /* 配列のbが終端に達していた場合、配列のaの残り部分を結合する */
        }
    }

    for (i = 0; i < M+N; i++) printf("%d ", c[i]); // __(カ)__
    printf("\n");

    return 0;
}
