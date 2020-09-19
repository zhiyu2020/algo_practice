//
// Created by zhiyu on 2020/9/17.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sort {
    void bubbleSort(vector<int>& arr) {
        if (!arr || arr.size() < 2) return;
        for (int end = arr.size() - 1; end > 0; end--) {// 从最后一个开始计数
            for (int i = 0; i < end; i++) { // 从头开始比较相邻数目
                if (arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                }
            }
        }
    }

    void swap(vector<int> arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};


// 对数器 绝对对的方法 for test
void sortFromSys(vector<int>& arr) {
    arr.sort();
}

//
vector<int> generateRandomArray(int size, int value) {
    vector<int> arr((int)(size + 1) * rand());
}