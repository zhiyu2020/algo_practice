//
// Created by zhiyu on 2020/9/15.
//

//
// Created by zhiyu on 2020/9/14.
//
// input: [2,3,1,0,2,5,3]
// output: 2 or 3
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

// reference: https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/mian-shi-ti-03-shu-zu-zhong-zhong-fu-de-shu-zi-yua/
// 解法一 BF: 暴力法 O(N^2)
class Solution {
public:
    int findRepeatNumber(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    res = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

// 解法二: 使用hash表来得到结果
class Solution2 {
public:
    int findRepeatNumber(vector<int> &nums) {
        unordered_map<int, bool> map;
        int n = nums.size();
        for (int num: nums) {
            if (map[num]) return num;
            else map[num] = true;
        }
        return -1;
    }
};

// 解法三:
// 原地交换
// 数组中 索引和val是一对多的情况
// 通过遍历数组通过交换操作 使元素的索引和值一一对应 nums[i] = i
// 通过索引映射对应的val 起到与字典等价的作用

// procedure:
// 1.遍历数组nums 设索引初始值i = 0
//      1.若nums[i] = i
class Solution3 {
public:
    int findRepeatNumber(vector<int> &nums) {
        int init = 0;
        while (init < nums.size()) {
            if (nums[init] == init) { // nums[i] = i 跳过
                init++;
                continue;
            } else if (nums[init] == nums[nums[init]]) {// nums[i] == nums[nums[i]]
                return nums[init];
            }
            swap(nums[init], nums[nums[init]]);
        }
        return -1;
    }
};

int main() {
    Solution test;
    string line1Vec, tmp;
    vector<int> line1V;
    getline(cin, line1Vec);
    stringstream line1Input(line1Vec);
    while (getline(line1Input, tmp, ',')) {
        int intVal = atoi(tmp.c_str());
        line1V.push_back(intVal);
    }

    cout << test.findRepeatNumber(line1V);
    return 0;
}
