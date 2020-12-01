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
    Matrix(int n = 1, int m = 1)
    {
        this->n = n;
        this->m = m;
        p = new float[n*m];
        f = new float[n];
        x = new float[m];
        for(int i = 0; i < n*m; i++)
            p[i] = 0;
        for(int i = 0; i < n; i++)
            f[i] = 0;
        for(int i = 0; i < m; i++)
            x[i] = 0;
    }
    ~Matrix()
    {
        delete[] p;
    }
    void initialize();
    void show();
    void swap_lines(int line1, int line2);
    void summator(int line_receiver, int line_transmitter, float factor);
    bool gauss();
    void show_solution();
};


void Matrix::initialize()
{
    for(int i = 0; i < n * m; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> f[i];
}

void Matrix::show()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << *(p + m * i + j) << " ";
        cout << "= " <<f[i] << endl;
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
    tmp = f[line1];
    f[line1] = f[line2];
    f[line2] = f[line1];
}

void Matrix::summator(int line_receiver, int line_transmitter, float factor)
{
    for(int j = 0; j < m; j++)
        *(p + line_receiver * m + j) += *(p + line_transmitter * m + j) * factor;
    f[line_receiver] += f[line_transmitter] * factor;
}

bool Matrix::gauss()
{
    for(int k = 0; k < n - 1; k++)
    {
        int l;
        for(l = k; l < n; l++)
        {
            if(*(p + l * m + k) != 0)
            {
                swap_lines(l, k);
                break;
            }
            else if(l == n) continue;
        }
        for(int i = k + 1; i < n; i++)
        {
            float tfactor = *(p + i * m + k)/(*(p + k * m + k));
            summator(i, k, -tfactor);
        }
    }
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

int main()
{
    int k;
    cout << "Введите порядок матрицы: "<< endl;
    cin >> k;
    Matrix ob(k, k);
    cout << "Введите матрицу, а затем свободные члены: "<< endl;
    ob.initialize();
    if(ob.gauss()){
        cout << "Система совместна и вот решения." << endl;
        ob.show_solution();
    }
    else
        cout << "Система несовместна." << endl;
    ob.show();
}
