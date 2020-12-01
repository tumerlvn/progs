#include <iostream>
#include <string>
#include <vector>

using namespace std;

long merge(long* ptr1, int size1, long* ptr2, int size2)
{
    long cnt = 0;
    long* ptrcpy1 = new long[size1];
    long* ptrcpy2 = new long[size2];
    for(int i = 0; i < size1; i++)
        ptrcpy1[i] = ptr1[i];
    for(int i = 0; i < size2; i++)
        ptrcpy2[i] = ptr2[i];
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i < size1 + size2; i++)
    {
        if(index1 == size1)
        {
            for(int j = i; index2 < size2; j++, index2++)
                ptr1[j] = ptrcpy2[index2];
            break;
        }
        else if(index2 == size2)
        {
            for(int j = i; index1 < size1; j++, index1++)
                ptr1[j] = ptrcpy1[index1];
            break;
        }

        if(ptrcpy1[index1] <= ptrcpy2[index2])
        {
            ptr1[i] = ptrcpy1[index1];
            index1++;
        }
        else
        {
            ptr1[i] = ptrcpy2[index2];
            index2++;
            cnt += size1 - index1;
        }
    }
    return cnt;
}

long* merge_sort(long* ptr, int l, int r, long &cnt)
{
    if(l < r)
    {
        int m = (l+r)/2;
        cnt += merge(merge_sort(ptr, l, m, cnt), m - l + 1, merge_sort(ptr, m+1, r, cnt), r - m);
    }
    return (ptr + l);
}

int main()
{
    int n;
    long cnt = 0;
    cin >> n;
    long* p = new long[n];
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    p = merge_sort(p, 0, n-1, cnt);
    cout << cnt << endl;
}
