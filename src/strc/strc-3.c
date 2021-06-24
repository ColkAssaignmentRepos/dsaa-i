//
// Created by Manaki ITO on 2021/06/24.
//
#include <stdio.h>

#define LENGTH 6

typedef struct {
    int math;
    int english;
    float average;
    char *name;
} student;

float average_of_two_nums(long long int a, long long int b);

void calculate_average(student *head_ptr, long long int student_num);

void show_students_table(student *head_ptr, long long int student_num);


int main(void) {
    student students[LENGTH] = {
            {78, 67, -1.0, "James"},
            {92, 82, -1.0, "John"},
            {85, 79, -1.0, "Mary"},
            {78, 81, -1.0, "Susan"},
            {72, 82, -1.0, "Brian"},
            {84, 77, -1.0, "Ruth"}
    };

    calculate_average(students, LENGTH);
    show_students_table(students, LENGTH);

    return 1;
}


float average_of_two_nums(long long int a, long long int b) {
    long long int sum;
    float result;

    sum = a + b;

    result = (float) sum / (float) 2;

    return result;
}


void calculate_average(student *head_ptr, long long int student_num) {
    for (long long int i = 0; i < student_num; i++) {
        head_ptr[i].average = average_of_two_nums(head_ptr[i].math, head_ptr[i].english);
    }

    return;
}


void show_students_table(student *head_ptr, long long int student_num) {
    printf("No.     Name    Math.   Eng.    Ave.    \n");

    for (long long int i = 0; i < student_num; i++) {
        printf("%-8lld%-8s%-8d%-8d%-8.1f\n",
               i+1, head_ptr[i].name, head_ptr[i].math, head_ptr[i].english, head_ptr[i].average);
    }

}
