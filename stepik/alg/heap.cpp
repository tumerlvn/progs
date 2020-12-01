#include <iostream>
#include <string>
#include <vector>

using namespace std;

void insert(vector<int> &Heap, int x)
{
    Heap.push_back(x);
    int i = Heap.size() - 1;
    while(i > 0 && Heap[i] > Heap[(i-1)/2])
    {
        swap(Heap[i], Heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax(vector<int> &Heap)
{
    swap(Heap[0], Heap[Heap.size() - 1]);
    int max = Heap.back();
    Heap.pop_back();
    int i = 0;
    if(Heap.size()%2)
        while(2*(i + 1) < Heap.size() && (Heap[i] < Heap[2*(i+1)-1] || Heap[i] < Heap[2*(i+1)]))
        {
            if(Heap[2*(i+1)-1] > Heap[2*(i+1)])
            {
                swap(Heap[2*(i+1)-1], Heap[i]);
                i = 2*(i+1)-1;
            }
            else
            {
                swap(Heap[2*(i+1)], Heap[i]);
                i = 2*(i+1);
            }
        }
    else
    {
        if(2*(i+1) == Heap.size())
        {
            if(Heap[2*(i+1) - 1] > Heap[i])
                swap(Heap[2*(i+1)-1], Heap[i]);
        }
        else
        while(2*(i+1)-1 < Heap.size() && (Heap[i] < Heap[2*(i+1)-1] || Heap[i] < Heap[2*(i+1)]))
        {
            if(Heap[2*(i+1)-1] > Heap[2*(i+1)])
            {
                swap(Heap[2*(i+1)-1], Heap[i]);
                i = 2*(i+1)-1;
            }
            else
            {
                swap(Heap[2*(i+1)], Heap[i]);
                i = 2*(i+1);
            }
            if(2*(i+1) == Heap.size())
            {
                if(Heap[2*(i+1) - 1] > Heap[i])
                    swap(Heap[2*(i+1)-1], Heap[i]);
                break;
            }

        }
    }
    return max;
}

int main()
{
    vector<int> Heap;
    vector<int> res;
    int cnt;
    string op;
    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        cin >> op;
        if(op == "Insert")
        {
            int tmp;
            cin >> tmp;
            insert(Heap, tmp);
        }
        else
        {
            res.push_back(extractMax(Heap));
        }
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i]<< endl;
}
