#include <iostream>

using namespace std;

int main(){
    int a;
    int n = 1;
    int i;
    cin >> a;
    for(i = 2; n <= a; ++i){
        n += i;//(n - i + 1) = (i - 1)(i)/2 <= a
    }
    cout << i - 2 << endl;
    for(int j = 1; j < i - 2; j++){
        cout << j << " ";
    }
    cout << a - (n - i + 1) + i - 2 << endl;
    return 0;
}
