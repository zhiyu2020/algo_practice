//
// Created by zhiyu on 2020/9/14.
//
// input: [2,3,1,0,2,5,3]
// output: 2 or 3
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 解法一 BF: 暴力法 O(N^2)
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
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
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (++map[nums[i]] > 1) { // 首先进行分析
                return nums[i];
            }
        }
        return 0;
    }
};
int main() {
    Solution test;
    cin >>
}
