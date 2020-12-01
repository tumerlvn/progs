#include <iostream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

void showMatrix(vector<vector<int>> matrix);

void matrixRotation(vector<vector<int>> &matrix, int r)
{



        int rowend = matrix.size()- 1;
        int colend = matrix[0].size() - 1;
        int rinit = 0;
        int cinit = 0;


        while(cinit < colend && rinit < rowend){
            int perimeter = 2 * ((rowend - rinit) + (colend - cinit));
            vector<int> tmp(perimeter);
            tmp[r%perimeter] = matrix[rinit][cinit];
            int i = rinit + 1;
            int j = cinit;
            for(int k = 1; k < perimeter; k++){

                tmp[(k + r)%perimeter] = matrix[i][j];

                if(i == rinit)
                    j--;
                else if(j == colend)
                    i--;
                else if(i == rowend)
                    j++;
                else if(j == cinit)
                    i++;
            }

            matrix[rinit][cinit] = tmp[0];
            i = rinit + 1;
            j = cinit;
            for(int k = 1; k < perimeter; k++){

                matrix[i][j] = tmp[k];

                if(i == rinit)
                    j--;
                else if(j == colend)
                    i--;
                else if(i == rowend)
                    j++;
                else if(j == cinit)
                    i++;
            }
            rinit++;
            cinit++;
            rowend--;
            colend--;
        }
        showMatrix(matrix);

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
