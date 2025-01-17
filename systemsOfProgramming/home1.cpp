#include <iostream>

using namespace std;

class myString {
    char *str;
    char size;
 public:
    myString(const char *arr = NULL, int n = 0) {
        size = n;
        str = new char[size + 1];
        if (arr != NULL) {
            for (int i = 0; i < size; i++) {
                str[i] = arr[i];
            }
        }
        str[size] = '\0';
    }
    void myPrint() {
        for (int i = 0; i < size; i++) {
            cout << str[i];
        }
        cout << endl;
    }
};

int main() {
    char *str = new char[20];
    for (int i = 0; i < 20; i++) {
        cin >> str[i];
    }
    myString ob(str, 10);
    ob.myPrint();
    return 0;
}
