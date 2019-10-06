#include <gtest/gtest.h>
#include "../IZN1.h"

class Apptest:
        public testing::Test
{
    void SetUp()
};


F_TEST(rowcalctest)
{
    int row=5;
    int column=5;
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i=0; i<row; i++) {
    matrix[i] = (int *) malloc(column * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
    matrix[i][j] = (i + 1) * 10 + (j + 1);
    }
    }
    int bufrows=row;
    int bufcol=column;
    delete_row(matrix,0,row);
    EXPECT_EQ(bufrows-1,row);
}

