#include <gtest/gtest.h>
#include <cstddef>
extern "C" {
#include "../func.h"
}


TEST(NULL,checkrow)
{
    int row = 5;
    int column = 5;
    int **matrix = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *) malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }
    int bufrows=row;
    int bufcol=column;
    delete_row(matrix,0,&row);
    EXPECT_EQ(bufrows-1,row);
    EXPECT_GE(row,0);
}

TEST(NULL,checkcol)
{
    int row=5;
    int column=5;
    int **matrix = (int **) malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int *) malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }
    int bufrows=row;
    int bufcol=column;
    delete_column(matrix,row,&column,0);
    EXPECT_EQ(bufcol-1,column);
    EXPECT_GE(column,0);
}




