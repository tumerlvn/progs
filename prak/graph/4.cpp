#include <iostream>
using namespace std;

class labyrinth
{
    int n, m;
    char** ptr;
    bool** used;
public:
    labyrinth(int line = 2, int column = 2)
    {
        n = line;
        m = column;
        ptr = new char*[n];
        for(int i = 0; i < n; i++)
            ptr[i] = new char[m];
        used = new bool*[n];
        for(int i = 0; i < n; i++)
            used[i] = new bool[m];
    }
    labyrinth(const labyrinth &obj)
    {
        char** newp;
        newp = new char*[obj.n];
        for(int i = 0; i < obj.n; i++)
            newp[i] = new char[obj.m];
        for(int i = 0; i < obj.n; i++)
            for(int j = 0; j < obj.m; j++)
                newp[i][j] = obj.ptr[i][j];
    }
    ~labyrinth()
    {
        for(int i = 0; i < n; i++)
            delete[] ptr[i];
        delete[] ptr;
        for(int i = 0; i < n; i++)
            delete[] used[i];
        delete[] used;
    }
    void initialize();
    void show();
    void way(int start_x, int start_y);
};

void labyrinth::initialize()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> ptr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            used[i][j] = 0;
}

void labyrinth::show()
{
  for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < m; j++)
          cout << ptr[i][j] << " ";
      cout << endl;
  }
  cout << endl;
}

void labyrinth::way(int x, int y)
{
    used[x][y] = 1;
    if(ptr[x][y] == 'F')
        cout << "Координаты финиша: " << x<< " " << y<< endl;
    if(x - 1 >= 0 && ptr[x-1][y] != 'x' && used[x-1][y] == 0)
    {
        this->way(x-1, y);
    }
    if(x + 1 < n && ptr[x+1][y] != 'x' && used[x+1][y] == 0)
        this->way(x+1, y);
    if(y + 1 < m && ptr[x][y+1] != 'x' && used[x][y+1] == 0)
        this->way(x, y+1);
    if(y - 1 >= 0 && ptr[x][y-1] != 'x' && used[x][y-1] == 0)
        this->way(x, y-1);
}

int main()
{
    int n, m;
    cout << "Ведите размер лабиринта: " << endl;
    cin >> n >> m;
    labyrinth A(n, m);
    cout << "Инициилизируйте лабиринт: " << endl;
    A.initialize();
    int start_x, start_y;
    cout << "Введите координаты начала: " << endl;
    cin >> start_x >> start_y;
    A.way(start_x, start_y);
    cout << endl;
}
