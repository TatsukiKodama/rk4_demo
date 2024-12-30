#include <stdio.h>
#include <stdlib.h>
#include "./initialize.h"

FILE *open_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

double *initialize_array(int size) {
    double *array = malloc(size * sizeof(double));
    if (array == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return array;
}
