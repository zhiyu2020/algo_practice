#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <unordered_map>
using namespace std;

// 青蛙跳 f(0) = 1, f(1) = 1, f(2) = 2
// fib的数值 f(0) = 0, f(1) = 1, f(2) = 1
// 递归法: O(2^N) O(N)
class Solution {
public:
    int numWays(int n) {
        if (n = 1 || n == 0) return 1;
        return numWays(n - 1) + numWays(n - 2);
    }
};

// 记忆化递归:
// O(N) O(N)
class Solution1 {
public:
    int memorize[];
    int numWays(int n) {
        memorize[] = new int[n + 1];
        memset(memorize, -1,n + 1);
        return jump(n);
    }

    int jump(int n) {
        if (memorize[n] != -1) return memorize[n];
        if (n == 1 || n == 0) {
            return 1;
        }
        memorize[n] = (jump(n - 1) +jump(n - 2)) % 1000000007;
        return memorize[n];
    }
};

//动态规划
//时间复杂度O(N) 空间O(N)
class Solution2 {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
        }
        return dp[n];
    }
};


//O(1)空间复杂度dp
class Solution3 {
public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        int pre = 1, cur = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = (pre + cur) % 1000000007;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};