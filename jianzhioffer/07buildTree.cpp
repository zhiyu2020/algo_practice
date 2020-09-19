#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>
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

// 递归法
class Solution {
public:
    unordered_map<int, int> inorderIndex;// 中序遍历的pos
    vector<int> preorderGlobal, inorderGlobal;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderGlobal = preorder;
        inorderGlobal = inorder;
        for (int i = 0; i < inorderGlobal.size(); i++) {
            inorderIndex[inorderGlobal[i]] = i;
        }
        return DFS(0, preorderGlobal.size() - 1, 0, inorderGlobal.size() - 1);
    }
    // pre inorder的范围需要好好准备的
    TreeNode* DFS(int preBegin, int preEnd, int inBegin, int inEnd) {
        if (preBegin > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorderGlobal[preBegin]);
        int rootInorderPos = inorderIndex[root->val];
        root->left = DFS(preBegin + 1, preBegin + rootInorderPos - inBegin, inBegin, rootInorderPos - 1);
        root->right = DFS(preBegin + rootInorderPos - inBegin + 1, preEnd, rootInorderPos + 1, inEnd);
        return root;
    }
};

int main() {
    Solution solv;
    vector<int> pre, in;
    string str, tmp;
    getline(cin, str);
    stringstream stream(str);
    while (getline(stream, tmp, ',')) {
        int data = atoi(tmp.c_str());
        pre.push_back(data);
    }
    getline(cin, str);
    stringstream stream2(str);
    while (getline(stream2, tmp, ',')) {
        int data = atoi(tmp.c_str());
        in.push_back(data);
    }
    TreeNode* res = solv.buildTree(pre, in);
    cout << res->val << endl;
    return 0;
}