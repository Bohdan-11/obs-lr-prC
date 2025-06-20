#ifndef DATA_H
#define DATA_H
#include <stdio.h>

typedef struct {
    char name[50];
    int scores[5];
    double average;
} Student;

int loadStudents(const char *filename, Student *arr, size_t max);
void sortByAverage(Student *arr, size_t count);
void saveReport(const char *filename, Student *arr, size_t count);

#endif