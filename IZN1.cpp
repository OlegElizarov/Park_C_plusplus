#include <iostream>

using namespace std;



int main() {
    int row=0;
    int column=0;
    cin>>row>>column;
    int **matrix;

    matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int [column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = (i + 1) * 10 + (j + 1);
        }
    }

    int *buffer=new int [max(row,column)];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}