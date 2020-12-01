#include <iostream>
#include <ctime>

#define L 10

using namespace std;

int main()
{
    int a[L];
    srand(time(0));
    for(int i = 0; i < L; i++)
    {
        a[i] = rand()%100;
        cout << a[i] << endl;
    }
    for(int i = 1; i < L; i++)
    {
        for(int j = i - 1; j >= 0 && a[j+1] < a[j]; j--)
            swap(a[j+1], a[j]);
    }
    cout << "после сортировки"<< endl;
    for(int i = 0; i < L; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
