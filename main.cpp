#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

// description:
// n * m 二维数组中 每一行按照从左到右递增顺序排序  每一列从上到下递增顺序排序
// 请完成一个函数 输入这样的一个二维数组和一个整数 判断数组是否含有该整数

//exp:
/*
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
*/
// target=5 true
// target=20 false

// 二分查找法
//从matrix左下角元素开始遍历 与目标值对比:
//  matrix[i][j] > target i--
//  matrix[i][j] < target j++
//  matrix[i][j] = target true

//else return false
// O(M + N) O(1)
class Solution {
public:
    bool  findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size() - 1, cols = 0;
        while (rows >= 0 && cols < matrix[0].size()) {
            if (matrix[rows][cols] > target) rows--;
            else if (matrix[rows][cols] < target) cols++;
            else return true;
        }
        return false;
    }
};

int main() {
    Solution solv;
    int M, N;
    cout << "input rows & cols num:" << endl;
    cin >> M >> N;
    string strLine, tmp;
    vector<vector<int>> matrix(M, vector<int>(N));
    int target;
    cout << "input the target:" << endl;
    cin >> target;
    cout << "input the matrix please." << endl;
    for (int i = 0; i < M; i++) {
        getline(cin, strLine);// input cols include ','
        stringstream stream(strLine);
        while (getline(stream, tmp, ',')) {
            int matrixElementRow = atoi(tmp.c_str());
            matrix[i].push_back(matrixElementRow);
        }
    }
    cout << "target is in matrix:" << solv.findNumberIn2DArray(matrix,target);
}