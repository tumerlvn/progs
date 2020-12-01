#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class MyClass
{
public:
    int data;

    MyClass(int data)
    {
        this->data = data;
        cout << "Constructor " << this << endl;
    }

    MyClass(int data)
    {
        this->data = data;
        cout << "Constructor " << this << endl;
    }

    ~MyClass()
    {
        cout << "Destructor " << this << endl;
    }
};

void Foo(MyClass value)
{
    cout << "Foo вызвался " << endl;
}

int main()
{
    MyClass ob(0);
    Foo(ob);
    return 0;
}
