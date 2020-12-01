#include <iostream>

#define L 100

using namespace std;

class bigint
{
    int* a = new int[L];
public:
    bigint(int n = 0)
    {
        for(int j = 0; j < L; j++)
            a[j] = 0;
        int i = 0;
        while(n)
        {
            a[99 - i] = n%10;
            n = n/10;
            i++;
        }
    }
    bigint(const bigint &ob)
    {
        int* a = new int[L];
        for(int j = 0; j < L; j++)
            a[j] = ob.a[j];
    }
    ~bigint()
    {
        delete[] a;
    }

    bigint operator* (const bigint &ob)
    {
        bigint wow;
        for(int i = L - 1; i >= 0; i--)
            for(int j = L - 1; j >= 0; j--)
            {
                if(i + j < 99)
                    continue;
                wow.a[i + j - 99] += a[i] * ob.a[j];
            }
        for(int i = L - 1; i >= 1; i--)
            if(wow.a[i] > 9)
            {
                wow.a[i-1] += wow.a[i]/10;
                wow.a[i] %= 10;
            }
        return wow;
    }

    bigint& operator= (const bigint &ob)
    {
        if (a){
            delete[] a;
        }
        a = new int[L];

        for(int i = 0; i < L; i++)
            a[i] = ob.a[i];
        return *this;
    }
    void show()
    {
        int j = 0;
        for(j = 0; j < L; j++)
            if(a[j])
                break;
        for(int i = j; i < L; i++)
            cout << a[i];
        cout << endl;
    }
    void new_value(int n)
    {
        for(int j = 0; j < L; j++)
            a[j] = 0;
        int i = 0;
        while(n)
        {
            a[99 - i] = n%10;
            n = n/10;
            i++;
        }
    }
};

void extraLongFactorials(int n) {
    bigint k(1);
    bigint l;
    for(int i = 2; i <= n; i++)
    {
        l.new_value(i);
        k = k * l;
        k.show();
    }
    k.show();
}

int main()
{
    for(int i = 2; i < 26; i++)
    {
        extraLongFactorials(i);
        cout << endl;
    }
}
