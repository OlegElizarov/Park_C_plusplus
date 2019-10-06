#include <stdlib.h>
#include <stdio.h>

void delete_column(int *matr[],int row,int *col,int delcol)
{
    for(int k=0;k<row;k++) {
        for (int i = delcol; i < *col - 1; i++) {
            matr[k][i] = matr[k][i + 1];
        }
    }
    *col=*col-1;
}

void delete_row(int *matr[],int delrow,int *row)
{
    for (int i=delrow;i<*row-1;i++)
    {
        matr[i]=matr[i+1];
    }
    *row=*row-1;
}

void zero_dawn(int *matr[],int *rows, int *columns,int *res[])
{

    for (int i=0;i<*rows;i++)
        for (int j = 0; j <*columns ; ++j) {
            res[i][j]=matr[i][j];
        }

    int *buffer1=(int*) malloc(*columns*sizeof(int));
    int *buffer2=(int*) malloc(*rows*sizeof(int));
    int looper=0;
    for (int i = 0; i < *rows; i++)
    {
        for (int j = 0; j < *columns; j++)
        {
            if (matr[i][j]==0)
            {
                buffer1[j]=1;
                buffer2[i]=1;
                continue;
            }
        }
    }

    //deleting rows
    int i=0;
    while(i<=*rows)
    {
        if (buffer2[i] == 1)
        {
            delete_row(res,i-looper,&(*rows));
            buffer2[i] = 0;
            i--;
            looper++;
        }
        i++;
    }


    //deleting columns
    i=0;
    looper=0;
    while(i<=*columns)
    {
        if (buffer1[i] == 1)
        {
            delete_column(res, *rows, &(*columns), i-looper);
            buffer1[i] = 0;
            i--;
            looper++;
        }
        i++;
    }



}


int main() {

    int row=0;
    int column=0;
    scanf("%d%d",&row,&column);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
        matrix[i] = (int *) malloc(column * sizeof(int));
    }
    int **result = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
        result[i] = (int *) malloc(column * sizeof(int));
    }

    //input here
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    /*int *buffer1=(int*) malloc(column*sizeof(int));
    int *buffer2=(int*) malloc(row*sizeof(int));
    int looper=0;*/


    //test for zero elements
    matrix[0][0]=0;
    matrix[3][3]=0;


    /*
    //finding zero elements
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j]==0)
            {
                buffer1[j]=1;
                buffer2[i]=1;
                continue;
            }
        }
    }

    //deleting rows
    int i=0;
    while(i<=row)
    {
        if (buffer2[i] == 1)
        {
            delete_row(matrix,i-looper,&row);
            buffer2[i] = 0;
            i--;
            looper++;
        }
        i++;
    }


    //deleting columns
    i=0;
    looper=0;
    while(i<=column)
    {
        if (buffer1[i] == 1)
        {
            delete_column(matrix, row, &column, i-looper);
            buffer1[i] = 0;
            i--;
            looper++;
        }
        i++;
    }
    */

    zero_dawn(matrix,&row,&column,result);
    //print
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d%c",result[i][j],' ');
        }
        printf("\n");
    }
    return 0;
}

