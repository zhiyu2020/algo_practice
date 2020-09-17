#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
using namespace std;
// 从尾到头打印链表
// input head = [1, 3, 2]
// output [2, 3, 1]

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 法一 辅助栈法
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> resStack;
        ListNode* tmp = head;
        while (tmp) {
            resStack.push(tmp->val);
            tmp = tmp->next;
        }
        int len = resStack.size();
        vector<int> res(len);
        while (len) {
            res.push_back(resStack.top());
            resStack.pop();
            len--;
        }
        return res;
    }
};
// 法二 库函数:
//
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head) {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};

// 法三:

int main() {
    Solution solv;
    string ss, data;
    ListNode head(1);
    ListNode second(3), thrid(2);
    head.next = &second;
    head.next->next = &thrid;
    head.next->next->next = NULL;
    vector<int> res = solv.reversePrint(&head);
    for (auto i : res) {
        cout << i << ' ';
    }
    stringstream stream(ss);
}