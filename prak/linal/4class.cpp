#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
    int n;
    float** p;
    float* f;
    float* x;
public:
    Matrix(int n = 1)
    {
        this->n = n;
        p = new float*[n];
        for(int i = 0; i < n; i++)
            p[i] = new float[n];
        f = new float[n];
        x = new float[n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                p[i][j] = 0;
        for(int i = 0; i < n; i++)
            f[i] = 0;
        for(int i = 0; i < n; i++)
            x[i] = 0;
    }
    ~Matrix()
    {
        for(int i = 0; i < n; i++)
            delete[] p[i];
        delete[] p;
        delete[] f;
        delete[] x;
    }
    void initialize();
    void initialize_f();
    void show_x();
    void show();
    friend bool Diff(const Matrix &ob, float* x1, float eps);
    friend void jacobi(const Matrix &ob, float* x1);
    friend void seidel(const Matrix &ob, float* x1);
    friend void find_answers(const Matrix &ob, float* x1, float eps, int method);
};

void Matrix::initialize()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j];
}

void Matrix::initialize_f()
{
    for(int i = 0; i < n; i++)
        cin >> f[i];
}

void Matrix::show_x()
{
    for(int i = 0; i < n; i++)
        cout << "x" << i << " = " << x[i] << endl;
}

void Matrix::show()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << p[i][j];
        cout << endl;
    }
    cout << endl;
}

bool Diff(const Matrix &ob, float* x1, float eps)
{
    float s = 0;
    for (int i = 0; i < ob.n; i++)
        s += (x1[i] - ob.x[i]) * (x1[i] - ob.x[i]);
    return (sqrt(s) < eps);
}

void jacobi(const Matrix &ob, float* x1)
{
    float var;
    for (int i = 0; i < ob.n; i++)
    {
        var = 0;
        for (int j = 0; j < i; j++)
            var += (ob.p[i][j] * x1[j]);
        for (int j = i + 1; j < ob.n; j++)
            var += (ob.p[i][j] * x1[j]);
        ob.x[i] = (ob.f[i] - var) / ob.p[i][i];
    }
}

void seidel(const Matrix &ob, float* x1)
{
    float var;
    for (int i = 0; i < ob.n; i++)
    {
        var = 0;
        for (int j = 0; j < i; j++)
            var += (ob.p[i][j] * ob.x[j]);
        for (int j = i + 1; j < ob.n; j++)
            var += (ob.p[i][j] * x1[j]);
        ob.x[i] = (ob.f[i] - var) / ob.p[i][i];
    }
}

void find_answers(const Matrix &ob, float* x1, float eps, int method)
{
    if(method == 2)
        do{
            for (int i = 0; i < ob.n; i++)
                x1[i] = ob.x[i];//x2[]
            jacobi(ob, x1);
        }while (!Diff(ob, x1, eps));
    if(method == 1)
        do{
            for (int i = 0; i < ob.n; i++)
                x1[i] = ob.x[i];
            seidel(ob, x1);
        }while (!Diff(ob, x1, eps));
}

int main()
{
    int n, method;
    float eps;
    cout << "Введите размер матрицы: ";
    cin >> n;
    Matrix ob(n);
    float* x1 = new float[n];
    for(int i = 0; i < n; i++)
    {
        x1[i] = 0;
    }
    cout << "Ведите приближение: ";
    cin >> eps;
    cout << "Заполните матрицу А: " << endl << endl;
    ob.initialize();
    cout << "Введите свободные члены: " << endl << endl;
    ob.initialize_f();
    cout << endl << endl;
    cout << "Выберите метод: 1-Seidel, 2-Jacobi" << endl;
    cin >> method;
    find_answers(ob, x1, eps, method);
    cout << "Решение: " << endl;
    ob.show_x();
    delete[] x1;
}
