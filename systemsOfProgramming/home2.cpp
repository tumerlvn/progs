#include <iostream>
#include <cctype>

using namespace std;

class myString {
    char *str;
    char size;
 public:
    myString(const char *arr = NULL, int n = 0) {
        //cout << "CONSTR" << endl;
        size = n;
        str = new char[size + 1];
        if (arr != NULL) {
            for (int i = 0; i < size; i++) {
                str[i] = arr[i];
            }
        }
        str[size] = '\0';
    }
    myString(const myString &string) {
       // cout << "COPY" << endl;
        size = string.size;
        str = new char[size + 1];
        for (int i = 0; i < size; i++) {
            str[i] = string.str[i];
        }
        str[size] = '\0';
    }
    ~myString() {
        //cout << "DESTR" << endl;
        delete[] str;
    }

    myString& operator=(const myString &ob);
    myString operator+(const myString &ob);
    friend myString& operator!(myString &ob);
    myString& operator++();
    myString& operator++(int value);
    friend ostream& operator<<(ostream & os, const myString & ob) {
        for (int i = 0; i < ob.size; i++) {
            os << ob.str[i];
        }
        return os;
    }
    
};

myString& myString :: operator=(const myString &ob) {
    //cout << "=" << endl;
    if (this->str) {
        delete[] str;
    }
    this->size = ob.size;
    this->str = new char[size + 1];
    for (int i = 0; i < size; i++) {
        str[i] = ob.str[i];
    }
    str[size] = '\0';
    return *this; 
}

myString myString :: operator+(const myString &ob) {
    //cout << "+" << endl;
    myString tmp;
    int i;
    tmp.size = size + ob.size;
    tmp.str = new char[tmp.size + 1];
    for (i = 0; i < size; i++) {
        tmp.str[i] = str[i];
    }
    for (int j = 0; j < ob.size; j++, i++) {
        tmp.str[i] = ob.str[j];
    }
    return tmp;
}

myString& operator!(myString &ob) {
    for (int i = 0; i < ob.size/2; i++) {
        char c = ob.str[i];
        ob.str[i] = ob.str[ob.size - 1 - i];
        ob.str[ob.size - 1 - i] = c;
    }
    return ob;
}

myString& myString :: operator++() {
    this->str[0] = toupper(this->str[0]);
    return *this;
}

myString& myString :: operator++(int value) {
    this->str[size - 1] = toupper(this->str[size - 1]);
    return *this;
}

int main() {
    cout << "Введите строку состоящую из 20 символов или больше: " << endl;
    char *str = new char[20];
    for (int i = 0; i < 20; i++) {
        cin >> str[i];
    }
    cout << "Первые 10 символов запишутся в новый объект класса myString" << endl;
    myString ob(str, 10);
    myString ne(ob);
    cout << "Инкремент префиксный: " << ++ob << endl;
    cout << "Инкремент постфиксный: " << ob++ << endl;
    cout << "Reverse: " << !ob << endl;
    cout << "Конкатенация строк через +: " << ob + ne << endl;

    return 0;
}
