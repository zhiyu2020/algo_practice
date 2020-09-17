#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
// 替换空格
// s = "We are happy."
// "We%20are%20happy."

//procedure
//1 初始化: 空格数量count 字符串s的长度len
//2 统计空格数量: 遍历s 遇到空格就count++
//3 修改s的长度 : len + 2 * count
//4 倒序遍历修改: i指向原字符串尾部 j指向新字符串尾部, 当i == j jump
//      当s[i]不为空格时: 执行s[j] = s[i]
//      当 s[i] 为空格时：将字符串闭区间 [j-2, j] 的元素修改为 "%20" ；由于修改了 3 个元素，因此需要 j -= 2;
//5 return 已经修改的s

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        int count = 0;
        for (char i : s) {
            if (i == ' ') count++;
        }
        s.resize(len + count * 2);
        for (int front = len - 1, back = s.size() - 1; front < back; front--, back--) {
            if (s[front] != ' ') s[back] = s[front];
            else if (s[front] == ' ') {
                s[back] = '0';
                s[back - 1] = '2';
                s[back - 2] = '%';
                back -= 2;
            }
        }
        return s;
    }
};

int main() {
    Solution solv;
    string ss, data;
    getline(cin, ss);
    stringstream stream(ss);
    cout << solv.replaceSpace(ss) << endl;

}