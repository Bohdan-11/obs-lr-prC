#include "data.h"
#include <stdio.h>
#define MAX_STUDENTS 100
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    Student students[MAX_STUDENTS];
    int count = loadStudents(argv[1], students, MAX_STUDENTS);
    if (count < 0) {
        perror("Error opening input file");
        return 1;
    }
    sortByAverage(students, count);
    saveReport(argv[2], students, count);
    printf("Processed %d students. Report saved to %s\n", count, argv[2]);
    return 0;
}
