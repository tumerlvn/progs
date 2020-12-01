#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int n = floor(sqrt(l));
    int rows, cols;
    if(l > n*(n+1))
    {
        rows = n+1;
        cols = n+1;
    }
    else
    {
        rows = n;
        cols = n+1;
    }
    char** matrix = new char*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new char[cols];
    for(int i = 0; i < cols; i++)
        matrix[rows - 1][i] = 0;

    int i = 0;
    while(s[i])
    {
        *(*(matrix) + i) = s[i];
    }
}
