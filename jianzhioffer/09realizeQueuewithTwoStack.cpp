#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

//用两个栈实现Queue
// 加入队尾 appendTail()函数： 将数字 val 加入栈 A 即可。
//删除队首deleteHead()函数： 有以下三种情况。
//当栈 B 不为空： B中仍有已完成倒序的元素，因此直接返回 B 的栈顶元素。
//否则，当 A 为空： 即两个栈都为空，无元素，因此返回 -1−1 。
//否则： 将栈 A 元素全部转移至栈 B 中，实现元素倒序，并返回栈 B 的栈顶元素。

// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]

class CQueue {
public:
    stack<int> A, B;
    CQueue() {}

    void appendTail(int value) {
        A.push(value);
        return;
    }

    int deleteHead() {
        int topVal = 0;
        if (!B.empty()) {
            topVal = B.top();
            B.pop();
            return topVal;
        } else if (A.empty()) {
            return -1;
        }
        while (!A.empty()) {
            B.push(A.top());
            A.pop();
        }
        topVal = B.top();
        B.pop();
        return topVal;
    }
};

// 输入：
//["CQueue","appendTail","deleteHead","deleteHead"]
//[[],[3],[],[]]
//输出：[null,null,3,-1]
// CQueue,appendTail,deleteHead,deleteHead
// 0,3,0,0
int main() {
    CQueue que;
    vector<int> saveTmp;
    string str, tmp, str2;
    getline(cin, str);
    getline(cin, str2);
    stringstream ss(str);
    stringstream ss2(str2);
    //第二行的数字
    while (getline(ss2, tmp, ',')) {
        int data = atoi(tmp.c_str());
        if (data)
            saveTmp.push_back(data);
    }
    //第一行 Queue appendTail deleteHead
    int i = 0;
    while (getline(ss, tmp, ',')) {
        if (tmp == "CQueue") {
            cout << "null,";
        }
        if (tmp == "appendTail") {
            que.appendTail(saveTmp[i]);
            i++;
            cout << "null,";
        }
        else if (tmp == "deleteHead") {
            cout << que.deleteHead() << ",";
        }
    }
    return 0;
}
// ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
//[[],[],[5],[2],[],[]]
//输出：[null,-1,null,null,5,2]
// CQueue,deleteHead,appendTail,appendTail,deleteHead,deleteHead
// 0,0,5,2,0,0