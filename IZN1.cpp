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
    delete_row(matrix,1,row);
    delete_column(matrix,row,column,1);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }





    return 0;
}