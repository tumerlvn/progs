#include <iostream>
using namespace std;

struct stack
{
    int ptr[100];
    int tail = 0;
    void Push(int value);
    int Top();
    int Pop();
};

void stack::Push(int value)
{
    ptr[tail] = value;
    tail++;
}

int stack::Top()
{
    return ptr[tail - 1];
}

int stack::Pop()
{
    tail--;
    return ptr[tail];
}

///////////////////////////////////////////////////////////////////////////////

struct queue
{
    int ptr[100];
    int tail = 0;
    int head = 0;
    void Push(int value);
    int Top();
    int Pop();
};

void queue::Push(int value)
{
    ptr[tail] = value;
    tail++;
}

int queue::Top()
{
    return ptr[head - 1];
}

int queue::Pop()
{
    head++;
    return ptr[head - 1];
}

///////////////////////////////////////////////////////////////////////////////

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
    void dfs(int k);
    void bfs(int k);
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

void graph::dfs(int k)
{
    int current;
    stack A;
    A.Push(k);
    while(A.tail > 0)
    {
        current = A.Top();
        if(used[current] == 0){
            used[current] = 1;
            cout << "Вершина " << current + 1 << " посещена." << endl;
            cout << "Ищем соседние вершины " << current + 1 << endl;
        }
        for(int i = vertex - 1; i >= 0; i--)
        {
            if(*(ptr + current * vertex + i) == 1 && used[i] == 0)
            {
                A.Push(i);
            }
        }
        if(current == A.Top())
            cout << "Соседей у вершины " << A.Pop() + 1 << " не осталось." << endl;
    }
}

void graph::bfs(int k)
{
    int current;
    queue B;
    B.Push(k);
    used[k] = 1;
    while(B.head != B.tail)
    {
        current = B.Pop();
        cout << "Из очереди: вершина " << current + 1 << endl;
        for(int i = 0; i < vertex; i++)
        {
            if(*(ptr + current * vertex + i) == 1 && used[i] == 0)
            {
                cout << "Ищем соседа " << current + 1 << ": находим " << i + 1 << endl;
                B.Push(i);
                used[i] = 1;
            }
        }
        cout << "Ищем соседа " << current + 1 << ": нет." << endl;
    }
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    int n, m;
    cout << "Введите количество вершин и ребер: " << endl;
    cin >> n >> m;
    graph ob(n, m);
    cout << "Введите пары вершин: " << endl;
    ob.initialize();
    cout << "Какой метод использовать?" << endl;
    cout << "1-DFS, 0-BFS" << endl;
    int method;
    cin >> method;
    if(method)
        ob.dfs(0);
    else
        ob.bfs(0);
}
