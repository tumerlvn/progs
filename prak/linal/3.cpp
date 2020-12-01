#include <iostream>
using namespace std;

class Matrix
{
    int n;
    int m;
    float* p;
    float* f;
    float* x;
public:
    Matrix(int lines = 1, int cols = 1)
    {
        n = lines;
        m = cols;
        p = new float[n*m];
        f = new float[n];
        x = new float[m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(i == j) p[i*m + j] = 1;
                else p[i*m + j] = 0;
        for(int i = 0; i < n; i++)
            f[i] = 0;
        for(int i = 0; i < m; i++)
            x[i] = 0;
    }
    Matrix(const Matrix &ob)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                p[i*m + j] = ob.p[i*m + j];
        for(int i = 0; i < n; i++)
            f[i] = ob.f[i];
        for(int i = 0; i < m; i++)
            x[i] = ob.x[i];
    }
    ~Matrix()
    {
        delete[] f;
        delete[] x;
        delete[] p;
    }
    void initialize();
    float* get_column(int column);
    void set_column(float *cptr, int column);
    void set_f(float *fptr);
    void show();
    void swap_lines(int line1, int line2);
    void summator(int line_receiver, int line_transmitter, float factor);
    friend void gauss_form(Matrix &ob1, Matrix &ob2);
    friend Matrix get_reverse(Matrix &init);
    bool find_answers();
    void show_solution();
    float* get_x();
    Matrix& operator= (const Matrix &ob);
};

Matrix& Matrix::operator= (const Matrix &ob)
{
    if (p){
        delete[] p;
        delete[] x;
        delete[] f;
    }
    n = ob.n;
    m = ob.m;

    p = new float[n*m];
    f = new float[n];
    x = new float[m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            p[i*m + j] = ob.p[i*m + j];
    for(int i = 0; i < n; i++)
        f[i] = ob.f[i];
    for(int i = 0; i < m; i++)
        x[i] = ob.x[i];

    return *this;
}

void Matrix::initialize()
{
    for(int i = 0; i < n * m; i++)
        cin >> p[i];
}

float* Matrix::get_column(int column)
{
    float *tmp;
    tmp = new float[n];
    for(int i = 0; i < n; i++)
        tmp[i] = *(p + i * m + column);
    return tmp;
}

void Matrix::set_column(float *cptr, int column)
{
    for(int i = 0; i < n; i++)
        *(p + i * m + column) = *(cptr + i);
}

void Matrix::set_f(float *fptr)
{
    for(int i = 0; i < n; i++)
        f[i] = *(fptr + i);
}

void Matrix::show()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << *(p + m * i + j) << " ";
        cout << endl;
    }
    cout << endl;
}

void Matrix::swap_lines(int line1, int line2)
{
    float tmp;
    for(int j = 0; j < m; j++)
    {
        tmp = *(p + line1 * m + j);
        *(p + line1 * m + j) = *(p + line2 * m + j);
        *(p + line2 * m + j) = tmp;
    }
}

void Matrix::summator(int line_receiver, int line_transmitter, float factor)
{
    for(int j = 0; j < m; j++)
        *(p + line_receiver * m + j) += *(p + line_transmitter * m + j) * factor;
}

void gauss_form(Matrix &ob1, Matrix &ob2)
{
    float* p = ob1.p;
    int m = ob1.m;
    int n = ob1.n;
    for(int k = 0; k < n - 1; k++)
    {
        int l;
        for(l = k; l < n; l++)
        {
            if(*(p + l * m + k) != 0)
            {
                ob1.swap_lines(l, k);
                ob2.swap_lines(l, k);
                break;
            }
            else if(l == n) continue;
        }
        for(int i = k + 1; i < n; i++)
        {
            float tfactor = *(p + i * m + k)/(*(p + k * m + k));
            ob1.summator(i, k, -tfactor);
            ob2.summator(i, k, -tfactor);
        }
    }
}

bool Matrix::find_answers()
{
    for(int k = n - 1; k >= 0; k--)
    {
        x[k] = f[k];
        for(int i = k + 1; i < m; i++)
            x[k] -= x[i] * (*(p + k * m + i));
        if(*(p + k * m + k) == 0 && x[k] != 0)
            return false;
        else if(*(p + k * m + k) != 0)
            x[k] /= *(p + k * m + k);
    }
    return true;
}

void Matrix::show_solution()
{
    for(int i = 0; i < m; i++)
        cout << x[i] << " ";
    cout << endl;
}

float* Matrix::get_x()
{
    float *tmp;
    tmp = new float[m];
    for(int i = 0; i < m; i++)
        *(tmp + i) = *(x + i);
    return tmp;
}

Matrix get_reverse(Matrix &init)
{
    Matrix ed(init.n, init.m);
    gauss_form(init, ed);
    float* ed_x;
    for(int i = 0; i < init.m; i++)
    {
        ed_x = ed.get_column(i);
        init.set_f(ed_x);
        init.find_answers();
        ed_x = init.get_x();
        ed.set_column(ed_x, i);
    }
    return ed;
}

int main()
{
    int k;
    cout << "Введите порядок матрицы: "<< endl;
    cin >> k;
    Matrix ob(k, k);
    cout << "Введите матрицу: "<< endl;
    ob.initialize();
    Matrix reverse = get_reverse(ob);
    cout << "Обратная матрица: "<< endl;
    reverse.show();
}
