#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "/Users/colk/Repositories/ColkAssaignmentRepos/dsaa-i/src/list/data.txt"
#define DEFAULT_BUFFER_LENGTH 50

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

typedef struct _person {
    char name[50];
    char phone[50];
    struct _person *next;
} person;

person *find(person *head, char *query);

person *read_from_file(person **head, const char *filename);


int main(void) {
    person *head, *p, *tmp, *result;
    char input_buf[DEFAULT_BUFFER_LENGTH];

    head = NULL;
    printf("Reading from the file: \"%s\"\n", FILENAME);
    read_from_file(&head, FILENAME);

    printf("\n");

    /* 後から入力した順に出力 */
    p = head;
    while (p != NULL) {
        printf("name : %s\t phone number : %s\n", p->name, p->phone);
        p = p->next;
    }
    printf("\n");

    printf("Who do you want to look up?\n");
    scanf("%s", input_buf);
    printf("\n");

    result = find(head, input_buf);
    if (result == NULL) {
        printf("No match found in the linear list. (query: \"%s\")\n", input_buf);
    } else {
        printf("The name: \"%s\" found in the linear list.\n", input_buf);
        printf("name : %s\t phone number : %s\n", result->name, result->phone);
    }

    /* 後から入力した順に解放 */
    p = head;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }

    return 0;
}


person *find(person *head, char *query) {
    person *p;

    p = head;
    while (p != NULL) {
        if (strcmp(p->name, query) == 0) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}


person *read_from_file(person **head, const char *filename) {
    char name_buf[50];
    char phone_buf[50];
    person *p;
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fatal_with_message(1,
                           "[X] Error: Failed to open \"%s\".\n"
                           "Make sure the file name is correct and not accessed by any other process.\n",
                           filename);
    }

    p = *head;
    while( fscanf(fp,"%s %s", name_buf, phone_buf) != EOF ) {
        p = (person *) malloc(sizeof(person));
        if (p == NULL) {
            fatal_with_message(1,
                               "[X] Unexpected error in %s(): Failed to allocate memory.\n",
                               __func__);
        }

        strcpy(p->name, name_buf);
        strcpy(p->phone, phone_buf);

        p->next = *head;
        *head = p;
    }

    return *head;
}
