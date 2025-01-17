#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* tmp = res;
        int flag = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            
            int sum = x + y + flag;
            tmp->next = new ListNode(sum%10); 
            tmp = tmp->next;
            flag = (sum)/10;
            
            if (l1 != nullptr) {
                l1 = l1->next;    
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (flag) tmp->next = new ListNode(1);
            
        return res->next;
    }
};

int main() {
    ListNode a = ListNode(0); 
    cout << a.val << endl;
    return 0;
}
