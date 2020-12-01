#include <iostream>
using namespace std;

class graph
{
    int vertex;
    int edges;
    bool* ptr;
    int* list;
    bool* used;
public:
    graph(int n = 1, int m = 0)
    {
        vertex = n;
        edges = m;
        ptr = new bool[n*n];
        list = new int[n*n];
        used = new bool[n];
        for(int i = 0; i < n*n; i++)
        {
            *(ptr + i) = 0;
            *(list + i) = 0;
        }
    }
    ~graph(){
        delete[] ptr;
        delete[] used;
    }
    void initialize();
    void show();
    void show_list();
};

void graph::initialize()
{
    int a, b, cnt;
    for(int i = 0; i < edges; i++)
    {
        cin >> a;
        cin >> b;
        a--;
        b--;
        if(a == b) continue;
        *(ptr + a * vertex + b) = 1;
        *(ptr + b * vertex + a) = 1;
    }
    for(int i = 0; i < vertex; i++)
    {
        cnt = 1;
        for(int j = 0; j < vertex; j++)
            if(*(ptr + i * vertex + j))
            {
                *(list + i * vertex + cnt) = j + 1;
                cnt++;
            }
        *(list + i * vertex) = cnt - 1;
    }
}

void graph::show()
{
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++)
            cout << *(ptr + i * vertex + j) << " ";
        cout << endl;
    }
    cout << endl;
}

void graph::show_list()
{
    cout << "Количество Номер "<< endl;
    for(int i = 0; i < vertex; i++)
    {
        cout << *(list + i * vertex) << "          ";
        for(int j = 1; j < vertex; j++)
        {
            if(!*(list + i * vertex + j))
            {
                cout << endl;
                break;
            }
            cout << *(list + i * vertex + j) << " ";
        }
    }
    cout << endl;
}


int main()
{
    cout << "Введите количество вершин и ребер: " << endl;
    int n, m;
    cin >> n;
    cin >> m;
    graph ob(n, m);
    cout << "Введите пары вершин: " << endl;
    ob.initialize();
    cout << "Матрица смежности: " << endl;
    ob.show();
    cout << "Список смежности: " << endl;
    ob.show_list();
}
