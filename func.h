#ifndef GTEST_RUN_FUNC_H
#define GTEST_RUN_FUNC_H

void zero_dawn(int *matr[], int *rows, int *columns, int *(*res[]));
void delete_column(int *matr[], int row, int *col, int delcol);
void delete_row(int *matr[], int delrow, int *row);
#endif //GTEST_RUN_FUNC_H
