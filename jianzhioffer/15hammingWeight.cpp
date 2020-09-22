#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <unordered_map>
#include <string>
#include <queue>
#include <math.h>
using namespace std;


// 给你一根长度为 n 的绳子，
// 请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。
// 例如，把 9 表示成二进制是 1001，有 2 位是 1。
// 因此，如果输入 9，则该函数输出 2。
//
// bitmap 位运算

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        do {
            res += n & 1;
            n >>= 1;
        } while (n > 0);
        return res;
    }
};

// Solution2
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n > 0) {
            res ++;
            n &= n - 1;
        }
        return res;
    }
};


int main() {
    int m, n, k;
    Solution2 solv;
    cin >> m >> n >> k;
    cout << solv.movingCount(m, n, k);
    return 0;
}