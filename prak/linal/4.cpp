#include <iostream>
#include <cmath>

using namespace std;

// Условие окончания
bool Diff(double x1[10], double x2[10], int n, double eps){
    double s = 0;
    for (int i = 0; i < n; i++)
        s += (x1[i] - x2[i]) * (x1[i] - x2[i]);
    return (sqrt(s) < eps);
}

double okr(double x, double eps){
    int i = 0;
    while (eps != 1){
        i++;
        eps *= 10;
    }
    int okr = pow(double(10), i);
    x = int(x * okr + 0.5) / double(okr);
    return x;
}

void seidel(int n, double x1[10], double x2[10], double A[10][10], double f[10]){
    double var;
    for (int i = 0; i < n; i++){
        var = 0;
        for (int j = 0; j < i; j++)
            var += (A[i][j] * x2[j]);
        for (int j = i + 1; j < n; j++)
            var += (A[i][j] * x1[j]);
        x2[i] = (f[i] - var) / A[i][i];
    }
}

void jacobi(int n, double x1[10], double x2[10], double A[10][10], double f[10]){
    double var;
    for (int i = 0; i < n; i++){
        var = 0;
        for (int j = 0; j < i; j++)
            var += (A[i][j] * x1[j]);
        for (int j = i + 1; j < n; j++)
            var += (A[i][j] * x1[j]);
        x2[i] = (f[i] - var) / A[i][i];
    }
}

int main()
{
    double eps, A[10][10], f[10], x2[10], x1[10];
    int n, i, j, m = 0;
    int method;
    cout << "Введите размер матрицы: ";
    cin >> n;
    cout << "Ведите приближение ";
    cin >> eps;
    cout << "Заполните матрицу А: " << endl << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            cin >> A[i][j];
        }
    cout << endl << endl;

    cout << "Введите свободные члены: " << endl << endl;
    for (i = 0; i < n; i++){
        cin >> f[i];
    }
    cout << endl << endl;
    cout << "Выберите метод: 1-Seidel, 2-Jacobi";
    cin >> method;

    for (int i = 0; i < n; i++)
        x2[i] = 1;
    if(method == 1)
        do{
            for (int i = 0; i < n; i++)
                x1[i] = x2[i];
            jacobi(n, x1, x2, A, f);
        }while (!Diff(x2, x1, n, eps));
    if(method == 2)
        do{
            for (int i = 0; i < n; i++)
                x1[i] = x2[i];
            seidel(n, x1, x2, A, f);
        }while (!Diff(x2, x1, n, eps));
    cout << "Решение " << endl << endl;
    for (i = 0; i < n; i++)
        cout << "x" << i << " = " << okr(x2[i], eps) << "" << endl;
    return 0;
}

/*
Ход метода, где:
a[n][n] - Матрица коэффициентов
x2[n], x1[n] - Текущее и предыдущее решения
b[n] - Столбец правых частей
Все перечисленные массивы - вещественные и
должны быть определены в основной программе,
также в массив x2[n] следует поместить начальное
приближение столбца решений (например, все нули)
*/
