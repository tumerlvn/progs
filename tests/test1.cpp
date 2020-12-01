#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    cout << "l is " << l << endl;
    int n = floor(sqrt(l));
    cout << "n is " << n << endl;
    int rows, cols;
    if(l > n*n)
    {
        rows = n;
        cols = n;
    }
    else
    {
        rows = n;
        cols = n+1;
    }
    char** matrix = new char*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new char[cols];
    int k = 0;
    int i = 0;
    int j = 0;
    while(s[k])
    {
        matrix[i][j] = s[k];
        j++;
        if(j == cols)
        {
            j = 0;
            i++;
        }
        k++;
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
            cout << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}
