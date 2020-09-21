#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
// 一个机器人从坐标 [0, 0] 的格子开始移动，
// 它每次可以向左、右、上、下移动一格（不能移动到方格外），
// 也不能进入行坐标和列坐标的数位之和大于k的格子。
// 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
// 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//
// 
// input: m = 2, n = 3, k = 1
// output: 3

// input: m = 3, n = 1, k = 0;
// output: 1

// DFS + backtrace
// 需要注意代码的模板结构:
// DFS 通过递归，先朝一个方向搜到底，再回溯至上个节点，沿另一个方向搜索，以此类推。

// O(MN) O(MN)
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (k == 0) return 1;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(visited, m, n, 0, 0, k);
    }

    int dfs(vector<vector<bool>>& visited, int m, int n, int row, int col, int k) {
        // terminator
        int sum = getSum(row) + getSum(col);
        if (row >= m || col >= n || visited[row][col] || sum > k) return 0;
        // process current level
        visited[row][col] = true;
        return 1 + dfs(visited, m, n, row + 1, col, k) + dfs(visited, m, n, row, col + 1, k);
    }

    int getSum(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

// BFS搜索:
class Solution2 {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que; // 连接两个需要用pair
        que.push({0, 0});
        int res = 0;
        visited[0][0] = true;
        while (!que.empty()) {
            auto front = que.front(); que.pop();
            int row = front.first;
            int col = front.second;
            res += 1;
            for (auto dir: directions) {
                int new_row = row + dir.first;
                int new_col = col + dir.second;
                if ( new_row < 0 || new_row >= m ||  new_col >= n \
                    || new_col < 0|| visited[new_row][new_col] || \
                    getSum(new_row, new_col) > k) {
                    continue;
                }
                que.push({new_row, new_col});
                visited[new_row][new_col] = true;
            }
        }
        return res;
    }

    int getSum(int i, int j) {
        int sum = 0;
        while (i) {
            sum += i % 10;
            i /= 10;
        }
        while (j) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
};



int main() {
    int m, n, k;
    Solution2 solv;
    cin >> m >> n >> k;
    cout << solv.movingCount(m, n, k);
    return 0;
}