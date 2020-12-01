#include <iostream>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int ch[128] = {0};
        int curCnt = 0;
        int maxCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            int k = s[i];
            if (ch[k] == 0) {
                ch[k] = i + 1;
                curCnt++;
            } else {
                int tmp = ch[k];
                for (int j = 0; j < 128; j++) {
                    if (ch[j] && ch[j] <= tmp) {
                        ch[j] = 0;
                    }
                }
                maxCnt = max(maxCnt, curCnt);
                curCnt = i + 1 - tmp;
                ch[k] = i + 1;
            }
        }
        maxCnt = max(maxCnt,curCnt);
        return maxCnt;
    }
};

int main() {
    string s;
    cin >> s;
    int res = Solution::lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}
