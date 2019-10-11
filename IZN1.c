#include "func.h"



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

