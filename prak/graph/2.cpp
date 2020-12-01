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
    void obhod(int k);
    void dfs(int k);
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

void graph::obhod(int k)
{
    used[k] = 1;
    cout << "Вершина " << k + 1 << " посещена." << endl;
    cout << "Ищем соседние вершины " << k + 1 << endl;
    for(int i = 0; i < vertex; i++)
    {

        if(*(ptr + k * vertex + i) == 1 && used[i] == 0)
            this->obhod(i);

    }
    cout << "Соседей у вершины " << k + 1 << " не осталось." << endl;
}

void graph::dfs(int k)
{
    used[k] = 1;
    cout << "Вершина " << k + 1 << " посещена." << endl;
    cout << "Ищем соседние вершины " << k + 1 << endl;
    for(int i = 1; i <= *(list + k * vertex); i++)
    {
        int next = *(list + k * vertex + i) - 1;
        if(!used[next])
            this->dfs(next);
    }
    cout << "Соседей у вершины " << k + 1 << " не осталось." << endl;
}



int main()
{
    int n, m;
    cout << "Введите количество вершин и ребер: " << endl;
    cin >> n >> m;
    graph ob(n, m);
    cout << "Введите пары вершин: " << endl;
    ob.initialize();
    cout << "Какую структуру вы используете?" << endl;
    cout << "1-Матрица смежности, 0-Список смежности" << endl;
    int method;
    cin >> method;
    if(method)
        ob.obhod(0);
    else
        ob.dfs(0);

}
