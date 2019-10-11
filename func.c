#include "func.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//finding zero elements and calling deleting functions
void zero_dawn(int *matr[], int *rows, int *columns, int *(*res[])) {

    int *buffer1 = (int *) malloc(*columns * sizeof(int));
    int *buffer2 = (int *) malloc(*rows * sizeof(int));
    int looper = 0;
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            if (matr[i][j] == 0) {
                //buffers with zero element's rows and columns
                buffer1[j] = 1;
                buffer2[i] = 1;
                continue;
            }
        }
    }

    //deleting rows
    int i = 0;
    size_t buf = *rows;
    while (i <= buf) {
        if (buffer2[i] == 1) {
            delete_row(matr, i - looper, &(*rows));
            buffer2[i] = 0;
            i--;
            looper++;
        }
        i++;
    }


    //deleting columns
    i = 0;
    buf = *columns;
    looper = 0;
    while (i <= buf) {
        if (buffer1[i] == 1) {
            delete_column(matr, *rows, &(*columns), i - looper);
            buffer1[i] = 0;
            i--;
            looper++;
        }
        i++;
    }
    *res = malloc(*rows * sizeof(int *));
    for (int i=0; i<*rows; i++) {
        (*res)[i] = malloc(*columns * sizeof(int));
    }

    for (int i = 0; i < (*rows) ; ++i) {
        for (int j = 0; j < (*columns) ; ++j) {
            (*res)[i][j]=matr[i][j];
        }
    }
}
