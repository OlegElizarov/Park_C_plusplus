#ifndef GTEST_RUN_IZN1_H
#define GTEST_RUN_IZN1_H

#endif //GTEST_RUN_IZN1_H

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