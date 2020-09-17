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
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/mian-shi-ti-06-cong-wei-dao-tou-da-yin-lian-biao-d/

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

// 法三: 递归方法
// 先走至链表末端 回溯时依次将节点值加入列表 这样就可以实现链表值的倒序
// T:O(N) S: O(N)
class Solution3 {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        iterMove2End(head);
        return res;
    }
    void iterMove2End(ListNode* head) {
        if (!head) return;
        iterMove2End(head->next);
        res.push_back(head->val);
    }
};

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
}