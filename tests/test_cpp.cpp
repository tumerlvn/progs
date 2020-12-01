#include <iostream>
using namespace std;

class xy
{
    int x, y;
public:
    xy(int i = 0, int j = 0){x = i; y = j;};
    xy operator+(xy ob2);
    xy operator=(xy ob2);
    void show();
};

xy xy::operator+(xy ob2)
{
    xy temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

xy xy::operator=(xy ob2)
{
    x = ob2.x;
    y = ob2.y;
    return *this;
}

void xy::show()
{
    cout << x << ", ";
    cout << y << "\n";
}

int main()
{
    xy ob1(5, 6);
    xy ob2(1, 2);
    ob2 = ob1 + ob1;
    ob2.show();
}
