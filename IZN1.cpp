#include <iostream>
#include <vector>

using namespace std;

void delete_row(vector <vector<int> > &matr,int delrow,int &row)
{
    matr.erase(matr.begin()+delrow);
    row--;
}

void delete_column(vector <vector<int> > &matr,int row,int &col,int delcol)
{
    for (int k = 0; k < row; ++k)
    {
        matr[k].erase(matr[k].begin() + delcol);
    }
    col--;
}

int main() {

    int row=0;
    int column=0;
    cin>>row>>column;

    vector< vector<int> > matrix(row);
    for (int i = 0; i < row; i++)
    {
        matrix[i].resize(column);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    matrix[1][1]=0;
    matrix[2][2]=0;
    matrix[0][0]=0;
    int *buffer=new int[column];
    int looper=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j]==0)
            {
                delete_row(matrix,i,row);
                buffer[j]=1;
                continue;
            }
        }
    }
    int i=0;
    while(i<column)
    {
            if (buffer[i] == 1)
            {
                delete_column(matrix, row, column, i-looper);
                buffer[i] = 0;
                i--;
                looper++;
            }
            i++;
    }





    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }





    return 0;
}