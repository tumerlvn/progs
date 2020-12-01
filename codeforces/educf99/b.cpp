#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int jcnt = 1;
        int i = 1;
        int k = 1;
        while (n > k) {
            i++;
            k += i;
            jcnt++; 
        }
        if (n == k) {
            cout << jcnt << endl;
        } else if (n == k - 1){
            cout << jcnt + 1 << endl;
        } else {
            cout << jcnt << endl;
        }
    }
    return 0;
}
