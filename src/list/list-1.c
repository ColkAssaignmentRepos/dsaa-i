#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    char name[50];
    char phone[50];
    struct _person *next;
} person;


int main(void) {
    int s, i;
    person *head, *p, *tmp;

    printf("How many people?\n");
    scanf("%d", &s);
    printf("\n");

    head = NULL;
    for (i = 1; i <= s; i++) {
        p = (person *) malloc(sizeof(person));
        if (p == NULL) {
            printf("can't get a memory space\n");
            return 1;
        }

        printf("Input name : ");
        scanf("%s", p->name);

        printf("Input phone number : ");
        scanf("%s", p->phone);

        p->next = head;
        head = p;
    }

    printf("\n");

    /* 後から入力した順に出力 */
    p = head;
    while (p != NULL) {
        printf("name : %s\t phone number : %s\n", p->name, p->phone);
        p = p->next;
    }
    printf("\n");

    /* 後から入力した順に解放 */
    p = head;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }

    return 0;
}
