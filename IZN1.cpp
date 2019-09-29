#include <iostream>
#include <vector>

using namespace std;



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

    matrix.erase(matrix.begin()+1);
    matrix[0].erase(matrix[0].begin()+1);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }




    
    return 0;
}