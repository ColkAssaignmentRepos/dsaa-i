//
// Created by Manaki ITO on 2021/06/24.
//
#include <stdio.h>

#define LENGTH 4

typedef struct {
    int score;
    char grade;
    char *name;
} student;

void show_students_table(student *head_ptr, long long int student_num);


int main(void) {
    student students[LENGTH] = {
            {78, 'B', "James"},
            {92, 'A', "John"},
            {85, 'A', "Mary"},
            {78, 'B', "Susan"}
    };

    show_students_table(students, LENGTH);

    return 1;
}


void show_students_table(student *head_ptr, long long int student_num) {
    printf("No.     Name    Score   Grade   \n");

    for (long long int i = 0; i < student_num; i++) {
        printf("%-8lld%-8s%-8d%-8c\n",
               i+1, head_ptr[i].name, head_ptr[i].score, head_ptr[i].grade);
    }

}
