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




int main() {

    int row=0;
    int column=0;
    scanf("%d%d",&row,&column);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
        matrix[i] = (int *) malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    int *buffer1=(int*) malloc(column*sizeof(int));
    int *buffer2=(int*) malloc(row*sizeof(int));
    int looper=0;

    matrix[0][0]=0;
    matrix[2][3]=0;

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
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d%c",matrix[i][j],' ');
        }
        printf("\n");
    }
    return 0;
}
