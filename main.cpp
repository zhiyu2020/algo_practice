#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

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
    stringstream stream(ss);
}