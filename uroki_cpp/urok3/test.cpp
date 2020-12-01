#include <iostream>
using namespace std;
auto foo(int x)
{
    if(x == 2) return 3;
    if(x == 1) return "ab";
    return foo(x-1);
}

int main()
{
    cout << foo(5);
}
