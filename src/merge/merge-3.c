#include <stdio.h>

#define N 12

int a[] = {78, 24, 67, 90, 31, 46, 12, 8, 34, 82, 56, 14};
int buff[(N/2)+1]; /* 一時的にデータを格納するための配列 */

void merge(int left, int right); /* マージソート (関数のプロトタイプ宣言) */
void disp(int a[]); /* データ表示 (関数のプロトタイプ宣言) */


int main(void) {
    disp(a);
    merge(0, N-1);
    disp(a);
}


void merge(int left, int right) {
    int center, i, j, k, p;

    if (left < right) {
        center = (left + right) / 2; /* データの中央位置を求める */
        merge(left, center); /* 前半部データをソート (再帰) */
        merge(center + 1, right); /* 後半部データをソート (再帰) */

        p = 0;
        for (i = left; i <= center; i++) buff[p++] = a[i];
        /* 前半部データ (ソート済み) を配列buffに格納 */

        j = 0;
        k = left;

        while (i <= right && j < p) {
            /* 配列aとbuffのデータをマージする。配列aまたはbuffのどちらかの
             * 終端に到達するまで、以下の処理を実行する */

            if (buff[j] <= a[i]) a[k++]=buff[j++];
            else a[k++]=a[i++];
        }

        while (j < p) a[k++]=buff[j++];
        /* 配列buffにデータが残っている場合は、それらすべてを配列にaに格納する */
    }
}


void disp(int a[]) {
    int i;
    for (i = 0; i < N; i++) printf("%4d", a[i]);
    printf("\n");
}
