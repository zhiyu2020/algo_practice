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
// 请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
// 每段绳子的长度记为 k[0],k[1]...k[m-1] 。
// 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
// 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，
// 此时得到的最大乘积是18。
//

//greedy algo:
// 在最优解下考虑其中任意一段x可能的取值
//
//因为 x >= 5x>=5 时 3 * (x - 3) > x3∗(x−3)>x，所以 x<5x<5
//若x == 4x==4，则 x = 2 * 2x=2∗2
//若x == 1x==1，则显然不会是最优解
//所以 xx 只能是 2 或 3
//又如果含有 3 个以上的 2，则 2 * 2 * 2 < 3 * 32∗2∗2<3∗3，所以最多只有两个 2
//综上所述，最优解只能被分解成 3 和 2，且 2 最多只能有两端

//乘积必须是以3为底数 得到乘积公式 x^a * b
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return 1 * (n - 1);
        int quoient = n / 3;
        int rest = n % 3;
        if (rest == 0) {
            return pow(3,quoient);
        }
        else if (rest == 1) {
            return pow(3, quoient - 1) * 4;
        }
        return pow(3, quoient) * 2;
    }
};

// DP动态规划
// 最优子结构
// 定义数组dp dp[i]表示长度为i的绳子能得到的最大乘积
// 先把长度为i的绳子拆成两部分 j , i -j 会有以下四种情况
// 1，j和i-j都不能再拆了
//dp[i]=j*(i-j);

//2，j能拆，i-j不能拆
//dp[i]=dp[j]*(i-j);

//3，j不能拆，i-j能拆
//dp[i]=j*dp[i-j];

//4，j和i-j都能拆
//dp[i]=dp[j]*dp[i-j];
//
// dp[i] = max(dp[i], (max(j, dp[j])) * (max(i - j, dp[i - j])))

class Solution2 {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main() {
    int m, n, k;
    Solution2 solv;
    cin >> m >> n >> k;
    cout << solv.movingCount(m, n, k);
    return 0;
}