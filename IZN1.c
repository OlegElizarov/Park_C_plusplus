#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "func.h"

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

int main() {

    int row=0;
    int column=0;
    scanf("%d%d",&row,&column);
    //size must be >0
    assert(row>0);
    assert(column>0);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
        matrix[i] = (int *) malloc(column * sizeof(int));
    }
    int **result;

    //input here
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    zero_dawn(matrix,&row,&column,&result);


    //print result
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) {
            printf("%d%c",result[i][j],' ');
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    return 0;
}

