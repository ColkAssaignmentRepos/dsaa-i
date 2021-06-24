//
// Created by Manaki ITO on 2021/06/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILENAME "data.txt"
#define POINT_BORDER 85
#define DEFAULT_BUFFER_BYTES 4096

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define fatal_with_message(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

typedef struct {
    int score;
    float deviation_score;
    char name[DEFAULT_BUFFER_BYTES];
} student;

void show_students_table(student *head_ptr, long long int student_num);

void show_general_info(double average, double standard_deviation_score);

void show_only_highly_scored_students(student *head_ptr, long long int student_num);

double students_average(student *head_ptr, long long int student_num);

double calculate_students_standard_deviation(student *head_ptr, long long int student_num);

void calculate_deviation_score(student *head_ptr, long long int student_num);

long long int line_number(char *filename);


int main(void) {
    long long int students_num = line_number(FILENAME);
    int score_buf = 0;
    student *students = NULL;
    FILE *fp = NULL;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fatal_with_message(1,
                           "[X] Error: Failed to open \"%s\".\n"
                           "Make sure the file name is correct and not accessed by any other process.\n",
                           FILENAME);
    }

    students = malloc(sizeof(student) * students_num);
    if (students == NULL) {
        fatal_with_message(1,
                           "[X] Unexpected error in %s(): Failed to allocate memory.\n",
                           __func__);
    }

    for (long long int i = 0; i < students_num; i++) {
        fscanf(fp, "%s %d", students[i].name, &score_buf);
        students[i].score = score_buf;
    }

    calculate_deviation_score(students, students_num);

    show_general_info(
            students_average(students, students_num),
            calculate_students_standard_deviation(students, students_num)
    );
    puts("");
    show_only_highly_scored_students(students, students_num);

    return 1;
}


void show_students_table(student *head_ptr, long long int student_num) {
    printf("==================== ALL STUDENTS ====================\n");
    printf("No.       Name      Score     Dev.      \n");

    for (long long int i = 0; i < student_num; i++) {
        printf("%-10lld%-10s%-10d%-10.1lf\n",
               i+1, head_ptr[i].name, head_ptr[i].score, head_ptr[i].deviation_score);
    }
}


void show_general_info(double average, double standard_deviation_score) {
    printf("==================== GENERAL INFO ====================\n");
    printf("AVERAGE: %.1lf, STANDARD DEVIATION SCORE: %.1lf\n",
           average, standard_deviation_score);
}


void show_only_highly_scored_students(student *head_ptr, long long int student_num) {
    long long int highly_scored_students_count = 0;

    printf("================ HIGHLY SCORED STUDENTS ================\n");
    printf("No.       Name      Score     Dev.      \n");

    for (long long int i = 0; i < student_num; i++) {
        if (head_ptr[i].score >= POINT_BORDER) {
            highly_scored_students_count++;

            printf("%-10lld%-10s%-10d%-10.1lf\n",
                   i+1, head_ptr[i].name, head_ptr[i].score, head_ptr[i].deviation_score);
        }
    }

    printf("IN TOTAL: %lld\n", highly_scored_students_count);
}


double students_average(student *head_ptr, long long int student_num) {
    long long int sum = 0;

    for (long long int i = 0; i < student_num; i++) {
        sum += head_ptr[i].score;
    }

    return (double)sum / (double)student_num;
}


double calculate_students_standard_deviation(student *head_ptr, long long int student_num) {
    double average = students_average(head_ptr, student_num);
    double sum = 0;
    double result;

    for (long long int i = 0; i < student_num; i++) {
        sum += pow((head_ptr[i].score - average), 2.0);
    }

    result = sqrt(sum/(double)student_num);

    return result;
}


void calculate_deviation_score(student *head_ptr, long long int student_num) {
    double average = students_average(head_ptr, student_num);
    double standard_deviation_score = calculate_students_standard_deviation(head_ptr, student_num);

    for (long long int i = 0; i < student_num; i++) {
        head_ptr[i].deviation_score = ((double) head_ptr[i].score - average) / standard_deviation_score * 10 + 50;
    }
}


long long int line_number(char *filename) {
    FILE *fp;
    size_t read_size;
    char buf[DEFAULT_BUFFER_BYTES];
    long long int lines = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        fatal_with_message(1,
                           "[X] Unexpected error: Failed to allocate memory.\n"
                           "Make sure the file name is correct and not accessed by any other process.\n"
                           "Aborting")
    }

    while ((read_size = fread(buf, 1, DEFAULT_BUFFER_BYTES, fp)) > 0) {

        for (size_t i = 0; i < read_size; i++) {

            if (buf[i] == '\n') {
                lines++;
            }

        }

    }

    lines++;

    fclose(fp);

    return lines;
}
