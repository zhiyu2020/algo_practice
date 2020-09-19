#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <unordered_map>
#include <string>
using namespace std;

// 旋转数组最小数字
// input: [3, 4, 5, 1, 2]
// output: 1

// input: [2, 2, 2, 0, 1]
// output: 0

// sort即可
class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
};

// 二分查找:
// O(logN) O(1)
// 算法流程:
// 初始化: 声明i,j 双指针分别指向左右两端
// 循环二分: m = (i + j) / 2
//      1.nums[m] > nums[j] m一定在左排序数组 旋转点在[m + 1, j]=> i = m + 1
//      2.nums[m] < nums[j] m一定在右排序数组 旋转点x在[i, m]闭区间内 执行j = m
//      3.nums[m] = nums[j] 无法判断x的位置 j-- 缩小判断位置
class Solution1 {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else j--;
        }
        return numbers[i];
    }
};


// Optimize:
// 当nums[m] == nums[j] 一定有区间[i,m] or [m, j]内所有元素相等 对于此数组 可以
// 用线性查找来解决
class Solution2 {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else {
                int x = i;
                for (int k = i + 1; k < j; k++) {
                    if (numbers[k] < numbers[x]) x = k;
                }
                return numbers[x];
            }
        }
        return numbers[i];
    }
};

int main() {
    string str, data;
    vector<int> saveNumbers;
    Solution solv;
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, data, ',')) {
        int intVal = atoi(data.c_str());
        saveNumbers.push_back(intVal);
    }

    cout << solv.minArray(saveNumbers) << endl;
    return 0;
}

