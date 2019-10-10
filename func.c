#include "IZN1.h"
#include <stdlib.h>
#include <stdio.h>

//function for deleting columns, change their count
void delete_column(int *matr[], int row, int *col, int delcol) {
    for (int k = 0; k < row; k++) {
        for (int i = delcol; i < *col - 1; i++) {
            matr[k][i] = matr[k][i + 1];
        }
    }
    *col = *col - 1;
}
//function for deleting rows, change their count
void delete_row(int *matr[], int delrow, int *row) {
    for (int i = delrow; i < *row - 1; i++) {
        matr[i] = matr[i + 1];
    }
    *row = *row - 1;
}


//finding zero elements and calling deleting functions
void zero_dawn(int *matr[], int *rows, int *columns, int *res[]) {

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; ++j) {
            res[i][j] = matr[i][j];
        }

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
            delete_row(res, i - looper, &(*rows));
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
            delete_column(res, *rows, &(*columns), i - looper);
            buffer1[i] = 0;
            i--;
            looper++;
        }
        i++;
    }


}
