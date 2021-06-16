#include<stdio.h>

#define N 10

void quick(int a[], int left, int right);

void display(int a[]);

int main(void) {
    int a[N] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};

    display(a);
    quick(a, 0, N - 1);
    display(a);
    return (0);
}

void quick(int a[], int left, int right) {
    int s, t, i, j;

    if (left < right) {
        s = a[left]; /* 左端の数値を軸にする */
        i = left;
        j = right + 1;

        while (1) { /* 軸より小さいグループと大きいグループに分ける */
            while (a[++i] > s);
            while (a[--j] < s);
            if (i >= j) break;

            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        a[left] = a[j]; /* 軸の移動 */
        a[j] = s;

        quick(a, left, j - 1); /* 左部分列に対する再帰呼び出し */
        quick(a, j + 1, right); /* 右部分列に対する再帰呼び出し */
    }
}

void display(int a[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}
