#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <sstream>
using namespace std;

// HUAWEI OJ 7/29
//void helper(vector<string> stream, int n, int len) {
//    int size = stream.size();
//    int minLen = min(size, n + len);
//    string res = "";
//    int k = 0;
//    for (int i = n; i <= minLen; i++) {
//        res += stream[i - 1];
//        res += ';';
//        k++;
//        if (k % 20 == 0) {
//            cout << res << endl;
//            res = "";
//            k = 0;
//        }
//    }
//    if (res != "") cout << res << endl;
//
//}
//int main() {
//    string input, data;
//    vector<string> save;
//    int pos, len;
//    getline(cin, input);
//    cin >> pos >> len;
//    stringstream stream(input);
//    while (stream >> data) {
//        save.push_back(data);
//    }
//    helper(save, pos, len);
//    return 0;
//}

// Q2 司机评分题目
//double helper(int a, int b, int c) {
//    double time = (double)(a - b) / 10 + (double)b / 2 + (double)c * 15 / 2;
//    return time;
//}
//
//int compare(const pair<int, double>& a, const pair<int, double>& b) {
//    return a.second < b.second;
//}
//int main() {
//    string Line1, Line2, Line3, Line4, data;
//    int tmpData;
//    getline(cin, Line1);
//    getline(cin, Line2);
//    getline(cin, Line3);
//    getline(cin, Line4);
//    stringstream stream1(Line1), stream2(Line2), stream3(Line3), stream4(Line4);
//    vector<int> distance, stuckDistance, numLight, remark;
//    while (getline(stream1,data, ',')) {
//        tmpData = stoi(data);
//        distance.push_back(tmpData);
//    }
//    data = "";
//    while (getline(stream2, data, ',')) {
//        tmpData = stoi(data);
//        stuckDistance.push_back(tmpData);
//    }
//    data = "";
//    while (getline(stream3, data, ',')) {
//        tmpData = stoi(data);
//        numLight.push_back(tmpData);
//    }
//    data = "";
//    while (getline(stream4, data, ',')) {
//        tmpData = stoi(data);
//        remark.push_back(tmpData);
//    }
//    vector<double> times;
//    for (int i = 0; i < remark.size(); i++) {
//        double tmpVal = helper(distance[i], stuckDistance[i], numLight[i]);
//        times.push_back(tmpVal);
//    }
//
//    vector<pair<int, double>> res, cpres;
//    for (int i = 0; i < remark.size(); i++) {
//        pair<int, double> temp;
//        temp.first = i + 1;
//        temp.second = times[i];
//        res.push_back(temp);
//        cpres.push_back(temp);
//    }
////    for (auto i : cpres) {
////        cout << i.first << ";" << i.second << endl;
////    }
////find min use time driver
//    sort(res.begin(), res.end(), compare);
//    double minDriverUseTime = res[0].second;
//    int minDriverNum = res[0].first;
////    cout << "mindriver:" << minDriverNum << ';' << minDriverUseTime << endl;
//
//    // & max remark driver
//    // max remark dirver
//    int maxRemarkIdx = 0, maxRemarkVal = remark[0];
//    // find max remark 不止一个司机评分高 看分数
//    for (int i = 1; i < remark.size(); i++) {
//        maxRemarkVal = max(remark[i], maxRemarkVal);
//    }
//    for (int i = 0; i < remark.size(); i++) {
//        if (maxRemarkVal == remark[i]) {
//            if (cpres[i].second < (minDriverUseTime + 60)) {
//                cout << cpres[i].first << ';' << cpres[i].second;
//            }
//        }
//    }
//    return 0;
//}

// Q3 struct 结构体输出sizeof情况
// input:
//struct RecordList {
//    short recordListTotalValue;
//    long recordListTotalPrice;
//    struct RecordItem recordItem;
//};
//struct RecordItem {
//    char nameA;
//    char nameB;
//    short value;
//    long price;
//};
//sizeof(RecordList)
vector<string> split(const string& str, const string& delim) {
    vector<string> res;
    if ("" == str) return res;
    char* strs = new char[str.length() + 1];
    strcpy(strs, str.c_str());

    char* d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char* p = strtok(strs, d);
    while (p) {
        string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }
    return res;
}

int size(string s, unordered_map<string, string> map) {
    string contentsName = map[s];
    vector<string> array;
    string ss = contentsName.substr(0, contentsName.size() - 1);
    array = split(ss, "\\*");
    int res = 0;
    for (int i = 0; i < array.size(); i++) {
        string temp = array[i];
        if (temp.substr(4, 4) == "char") {
            res += 1;
        } else if (temp.substr(4, 4) == "long") {
            res += 4;
        } else if (temp.substr(4, 4) == "shor") {
            res += 2;
        } else {
            vector<string> structLine = split(temp.substr(4, temp.size() - 4), " ");
            res += size(structLine[1], map);
        }
    }
    return res;
}

int main() {
    string name = "", content = "";
    int flagForStructName = 0;
    unordered_map<string, string> mapForContent;
    string lines;
    while (getline(cin, lines)) {
        if (lines.substr(0, 6) == "sizeof") break;
        if (!flagForStructName) {
            //struct RecordList {
            name = lines.substr(7, lines.size() - 2 - 7); // ? size
            flagForStructName = 1;
        }  else if (lines == "};") {
            flagForStructName = 0;
            mapForContent.insert(make_pair(name, content));
            content = "";
        } else {
            content += lines;
            content += "*";
        }
    }
    //sizeof(RecordList)
    int sizeofStruct =  size(lines.substr(7, lines.size() - 1 - 7), mapForContent); // size ?
    cout << sizeofStruct;
    return 0;
}
