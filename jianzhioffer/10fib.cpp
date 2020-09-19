#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// F(0) = 0, F(1) = 1
// F(N) = F(N - 1) + F(N - 2) 其中N > 1

// f(0) = 0, f(1) = 1, f(2) = 1
// 递归法: O(2^N) O(N)
class Solution {
public:
    int fib(int n) {
        if (n <= 2) return n;
        return fib(n - 1) + fib(n - 2);
    }
};


// 记忆化递归法:
// 在递归的基础上 创建一个长度为n的数组 用于递归时存储f(0)至f(n)的数字值
class Solution1 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> memorize(n + 1);
        memorize[1] = 1;
        return dp(memorize, n);
    }

    int dp(vector<int>& memo, int n) {
        if (n <= 1) return n;
        while (memo[n])
            return memo[n];
        memo[n] = (dp(memo, n - 2) + dp(memo, n - 1)) % 100000007;
        return memo[n];
    }
};

// 动态规划:
class Solution3 {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
    }
};

int main() {

}