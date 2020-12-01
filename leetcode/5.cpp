#include <iostream>

using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        int ermi = 0, elmi = -1;
        int ormi = 0,  olmi = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int eri, eli;
            int ori, oli;
            if (s[i] == s[i+1]) {
                eri = i;
                eli = i+1;
                while (eri > 0 && eli < s.size() - 1 && s[eri-1] == s[eli+1]) {
                    eri--;
                    eli++;
                }
                if (eli - eri > elmi - ermi) {
                    elmi = eli;
                    ermi = eri;
                }
            }
            if (i+2 < s.size() && s[i] == s[i+2]) {
                ori = i;
                oli = i+2;
                while (ori > 0 && oli < s.size() - 1 && s[ori-1] == s[oli+1]) {
                    ori--;
                    oli++;
                }
                if (oli - ori > olmi - ormi) {
                    olmi = oli;
                    ormi = ori;
                }
            }
        }
        string result;
        if (olmi - ormi > elmi - ermi) {
            result = s.substr(ormi, olmi - ormi + 1);
        } else {
            result = s.substr(ermi, elmi - ermi + 1);
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution::longestPalindrome(s)<< endl;
}
