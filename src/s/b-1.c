#include<stdio.h>

#define NUM 5
#define MAX 10

void BinSort(int data[]) {
    int i, j, k = 0;
    int bin[MAX];
    for (i = 0; i < MAX; i++)
        bin[i] = 0;
    for (i = 0; i < NUM; i++)
        bin[data[i]]++;
    for (i = 0; i < MAX; i++) {
        for (j = bin[i]; j > 0; j--)
            data[k++] = i;
    }
}

int main() {
    int i;
    int data[NUM] = {6, 9, 3, 0, 5};
    printf("ソート前:\n");
    for (i = 0; i < NUM; i++)
        printf("%d ", data[i]);
    printf("\n");
    BinSort(data);
    printf("ソート後:\n");
    for (i = 0; i < NUM; i++)
        printf("%d ", data[i]);
    printf("\n");
    return (0);
}