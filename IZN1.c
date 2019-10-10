#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


//function for deleting columns, change their count
void delete_column(int *matr[],int row,int *col,int delcol)
{
    for(int k=0;k<row;k++) {
        for (int i = delcol; i < *col - 1; i++) {
            matr[k][i] = matr[k][i + 1];
        }
    }
    *col=*col-1;
}
//function for deleting rows, change their count
void delete_row(int *matr[],int delrow,int *row)
{
    for (int i=delrow;i<*row-1;i++)
    {
        matr[i]=matr[i+1];
    }
    *row=*row-1;
}


//finding zero elements and calling deleting functions
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
                //buffers with zero element's rows and columns
                buffer1[j]=1;
                buffer2[i]=1;
                continue;
            }
        }
    }

    //deleting rows
    int i=0;
    size_t buf=*rows;
    while(i<=buf)
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
    buf=*columns;
    looper=0;
    while(i<=buf)
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

// 000
// 230
// i=1  loop=1 col=2 buf12=0

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
    int **result = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
        result[i] = (int *) malloc(column * sizeof(int));
    }

    //input here
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d",&matrix[i][j]);
        }
    }

    //here we have full matrix
    zero_dawn(matrix,&row,&column,result);
    //here we have result matrix


    //print result
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) {
            printf("%d%c",result[i][j],' ');
        }
        printf("\n");
        //freeeeee
        free(result[i]);
    }
    free(result);
    return 0;
}

