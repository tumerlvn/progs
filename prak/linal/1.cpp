#include <iostream>
using namespace std;

class Matrix
{
    int order;
    float *p;
public:
    Matrix(int n = 1)
    {
        order = n;
        p = new float[order * order];
        for(int i = 0; i < order * order; i++)
            p[i] = 0;
    }
    Matrix(const Matrix &ob);
    ~Matrix()
    {
        delete[] p;
    }
    void initialize();
    void show();
    void swap_lines(int line1, int line2);
    void summator(int line_receiver, int line_transmitter, float factor);
    int triangle_form();//возвращает 0 если матрица вырождена, 1 в другом случае
    float determinant();//перемножает диагональные элементы
};

Matrix::Matrix(const Matrix &obj)
{
    float *newp;
    newp = new float[obj.order * obj.order];
    float *ptr1 = p;
    float *arr_end = obj.p + obj.order * obj.order;
    for(; newp != arr_end; ++newp, ++ptr1)
        *newp = *ptr1;
}

void Matrix::initialize()
{
    for(int i = 0; i < order * order; i++)
        cin >> p[i];
}

void Matrix::show()
{
    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
            cout << *(p + order * i + j) << " ";//p[i][j]
        cout << endl;
    }
    cout << endl;
}

void Matrix::swap_lines(int line1, int line2)
{
    float tmp;
    for(int j = 0; j < order; j++)
    {
        tmp = *(p + line1 * order + j);
        *(p + line1 * order + j) = *(p + line2 * order + j);
        *(p + line2 * order + j) = tmp;
    }
}

void Matrix::summator(int line_receiver, int line_transmitter, float factor)
{
    for(int j = 0; j < order; j++)
        *(p + line_receiver * order + j) += *(p + line_transmitter * order + j) * factor;
}

int Matrix::triangle_form()
{
    int temp = 1;
    float a, b;
    for(int i = 0; i < order - 1; i++)
    {
        for(int k = i; k < order; k++)
            if(*(p + k * order + i) != 0)
            {
                swap_lines(k, i);
                temp*= -1;
                break;
            }
        if(*(p + i * order + i) == 0)
        {
            temp = 0;
            break;
        }
        for(int j = i + 1; j < order; j++)
        {
            if(*(p + j*order + i) != 0 && *(p + i*order + i) != 0)
            {
                a = *(p + i*order + i);//p[i][i]
                b = *(p + j*order + i);//p[j][i]
                summator(j, i, -b/a);
            }
        }
    }
    return temp;
}

float Matrix::determinant()
{
    float result = 1;
    int k = this->triangle_form();
    if(k == 0)
        return 0;
    for(int i = 0; i < order; i++)
        result *= *(p + i*order + i);//p[i][i]
    return result*k;
}

int main()
{
    int k;
    cout << "Введите порядок матрицы: " << endl;
    cin >> k;
    Matrix ob1(k);
    cout << "Введите матрицу: " << endl;
    ob1.initialize();
    int f = ob1.determinant();
    cout << "Определитьль данной матрицы: " << f << endl;
    return 0;
}
