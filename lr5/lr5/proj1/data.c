#include "data.h"
#include <string.h>
#include <stdlib.h>

int loadStudents(const char *filename, Student *arr, size_t max) {
    FILE *f = fopen(filename, "r");

    if (!f) return -1;
    size_t count = 0;
    while (count < max && fscanf(f, "%49[^,],%d,%d,%d,%d,%d\n",
    arr[count].name,
    &arr[count].scores[0], &arr[count].scores[1],
    &arr[count].scores[2], &arr[count].scores[3],
    &arr[count].scores[4]) == 6) {
        // вычисляем средний балл
        int sum = 0;
        for(int i=0; i<5; ++i) sum += arr[count].scores[i];
        arr[count].average = sum / 5.0;
        count++;
    }

    fclose(f);
    return count;
}

void sortByAverage(Student *arr, size_t count) {
    // простая сортировка пузырьком по average
    for(size_t i=0; i<count; ++i) {
        for(size_t j=0; j<count-i-1; ++j) {
            if(arr[j].average < arr[j+1].average) {
                Student tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void saveReport(const char *filename, Student *arr, size_t count) {
    FILE *f = fopen(filename, "w");

    if (!f) return;
    fprintf(f, "Name,Average\n");

    for(size_t i=0; i<count; ++i) {
        fprintf(f, "%s,%.2f\n", arr[i].name, arr[i].average);
    }
    fclose(f);
}
