//
// Created by zhiyu on 2020/8/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//int climbStairs(int n) {
//    if (n <= 2) return n;
//    vector<int> dp(n,0);
//    dp[0] = 1;
//    dp[1] = 2;
//    for (int i = 2; i < n; i++) {// i = 3
//        dp[i] = dp[i - 1] + dp[i - 2]; // dp[]
//    }
//    return dp[n-1];
//}
//
//int maxGoodNum(string s) {
//    int cntG = 0, cntO = 0, cntd = 0;
//    int res = 0;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == 'G'){
//            cntG++;
//            s[i] = 'a';
//            for (int j = i + 1; j < s.size(); j++) {
//                if (s[j] == 'o') {
//                    cntO++;
//                    s[j] = 'a';
//                }
//                if (cntO == 2) {
//                    for (int m = j + 1; m < s.size(); m++) {
//                        if (s[m] == 'd') {
//                            res++;
//                            s[m] = 'a';
//                            cntG = 0;
//                            cntO = 0;
//                            cntd = 0;
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return res;
//}

void getResult(int n, vector<int>& res, int& count) {
    for (int a = 1; a <= 9; a++) {
        for (int c = 0; c <= 9; c++) {
            int tmp = n - 100 * a - 11 * c;
            if (tmp == n) break;
            int b = (tmp / 10) % 10;
            if ((tmp / 100 == a) && (tmp % 10 == c) && (a != c) && (a != b) && (b != c)) {
                count++;
                res.push_back(tmp);
            }
        }
    }
}

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> res;
    getResult(n, res, count);
    sort(res.begin(), res.end());
    cout << count << endl;

    for (auto i : res) {
        cout << i << " " << (n - i) << endl;
    }
    return 0;
}