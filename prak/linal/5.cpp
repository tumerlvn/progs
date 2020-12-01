#include <iostream>

#define L 100

using namespace std;

int main(){
    double matA[L][L], matB[L];//matrix - matA, free nums - matB
    double y, a[L], B[L], matRes[L];//d - y,alpha - a, beta - B, answers - matRes
    int n;//order of matrix

    cout << "Введите размер матрицы" << endl;
    cin >> n;
    cout << "Введите матрицу " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matA[i][j];
        }
    }
    cout << "Введите свободные члены " << endl;
    for(int i = 0; i < n; i++){
        cin >> matB[i];
    }
    y = matA[0][0];
    a[0] = -matA[0][1] / y;
    B[0] = matB[0] / y;
    for(int i = 1; i < n; i++){
        y = matA[i][i] + matA[i][i - 1] * a[i - 1];
        a[i] = -matA[i][i + 1] / y;
        B[i] = (matB[i] - matA[i][i - 1] * B[i - 1]) / y;
    }

    matRes[n - 1] = (matB[n - 1] - matA[n - 1][n - 2] * B[n - 2]) / (matA[n - 1][n - 1] + matA[n - 1][n - 2] * a[n - 2]);
    for(int i = n - 2; i >= 0; i--){
        matRes[i] = a[i] * matRes[i + 1] + B[i];
    }
    for(int i = 0; i < n; i++){
        cout << matRes[i] << " ";
    }
    return 0;
}
