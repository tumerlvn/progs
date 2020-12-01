#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
    int letters, wordSize;
    cin >> letters >> wordSize;

    vector<string> encryption(letters);
    cin.ignore(32767, '\n');
    for(int i = 0; i < letters; i++)
    {
        getline(cin, encryption[i]);
    }
    /*for(int i = 0; i < letters; i++)
    {
        cout << encryption[i] << endl;
    }*/

    string word;
    getline(cin , word);

    string result = "";
    int i = 0;
    string tmp = "";
    while(word[i])
    {
        tmp += word[i];
        for(int j = 0; j < letters; j++)
        {
            if(tmp == (string)&(encryption[j][3]))
            {
                result += encryption[j][0];
                tmp = "";
            }
        }
        i++;
    }
    cout << result << endl;
}
