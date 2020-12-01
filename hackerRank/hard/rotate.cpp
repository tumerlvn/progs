#include <iostream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

void showMatrix(vector<vector<int>> matrix);

void matrixRotation(vector<vector<int>> &matrix, int r)
{


    for(int j = 0; j < r; j++){
        int rowend = matrix.size()- 1;
        int colend = matrix[0].size() - 1;
        int rinit = 0;
        int cinit = 0;

        int tmp;
        while(cinit < colend && rinit < rowend){
            tmp = matrix[rinit][cinit];
            for(int i = rinit + 1; i <= rowend; i++)
                swap(tmp, matrix[i][cinit]);
            for(int i = cinit + 1; i <= colend; i++)
                swap(tmp, matrix[rowend][i]);
            for(int i = rowend - 1; i >= rinit; i--)
                swap(tmp, matrix[i][colend]);
            for(int i = colend - 1; i >= cinit; i--)
                swap(tmp, matrix[rinit][i]);
            rinit++;
            cinit++;
            rowend--;
            colend--;
        }
        showMatrix(matrix);
    }
}

void showMatrix(vector<vector<int>> matrix)
{
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void randomMatrix(vector<vector<int>> &matrix, int cols)
{
    for(int i = 0; i < matrix.size(); i++)
        matrix[i] = vector<int>(cols);
    srand(time(0));
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            matrix[i][j] = rand() % 10;
    }
}

int main()
{
    int n, m, r;
    cout << "Enter rows: " << endl;
    cin >> n;
    cout << "Enter cols: " << endl;
    cin >> m;
    cout << "Enter rotations: " << endl;
    cin >> r;
    vector<vector<int>> matrix(n);
    randomMatrix(matrix, m);
    showMatrix(matrix);



    matrixRotation(matrix, r);

}
