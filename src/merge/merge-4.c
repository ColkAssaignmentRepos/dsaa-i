#include <stdio.h>

#define N 12

int a[] = {78, 24, 67, 90, 31, 46, 12, 8, 34, 82, 56, 14};
int buff[(N/2)+1]; /* 一時的にデータを格納するための配列 */

void merge(int left, int right, int level); /* マージソート (関数のプロトタイプ宣言) */
void disp(int a[]); /* データ表示 (関数のプロトタイプ宣言) */
void annotation_at(int start_idx, int end_idx);
void indent_at_level(int level);


int main(void) {
    disp(a);
    merge(0, N-1, 0);
    disp(a);
}


void merge(int left, int right, int level) {
    int center, i, j, k, p;

    if (left < right) {
        center = (left + right) / 2; /* データの中央位置を求める */

        printf("SEGMENT:");
        disp(a);
        printf("%2d", level);
        annotation_at(left, center);

        merge(left, center, level + 1); /* 前半部データをソート (再帰) */

        printf("SEGMENT:");
        disp(a);
        printf("%2d", level);
        annotation_at(center + 1, right);

        merge(center + 1, right, level + 1); /* 後半部データをソート (再帰) */

        p = 0;
        for (i = left; i <= center; i++) {
            buff[p++] = a[i];
        }
        /* 前半部データ (ソート済み) を配列buffに格納 */

        j = 0;
        k = left;

        // ここでマージとソートが行われている
        if (i <= right && j < p) {
            printf("MERGING!");
            disp(a);
            printf("%2d\n", level);
        }
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


void indent_at_level(int level) {
    for (int i = 0; i < level; i++) {
        printf("| ");
    }
}


void disp(int a[]) {
    int i;
    for (i = 0; i < N; i++) printf("%4d", a[i]);
    printf("\n");
}


void annotation_at(int start_idx, int end_idx) {
    int i = 0;
    int j = 0;

    printf("  ");

    for (i = 0; i < start_idx; i++) {
        printf("    ");
    }

    for (j = i; j < end_idx + 1; j++) {
        printf("^^^^");
    }

    printf("\n");
}
