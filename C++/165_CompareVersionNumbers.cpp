#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <cassert>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
typedef pair<int, int> PII;
public:
    // 165. Compare Version Numbers
    vector<int> versionString2vector(string version){
        vector<int> p;
        int tmp = 0;
        for(int i = 0; i < version.size(); i++){
            if (version[i] == '.') {
                p.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp * 10 + version[i] - '0';
            }
        }
        p.push_back(tmp);
        return p;
    }
    int compareVersion(string version1, string version2) {
        vector<int> p1, p2;
        p1 = versionString2vector(version1);
        p2 = versionString2vector(version2);
        if (p1.size() < p2.size()){
            for(int i = 0; i <= p2.size() - p1.size(); i++){
                p1.push_back(0);
            }
        }
        if (p1.size() > p2.size()){
            for(int i = 0; i <= p1.size() - p2.size(); i++){
                p2.push_back(0);
            }
        }
        //showV(p1);
        //showV(p2);
        for(int i = 0; i < p1.size(); i++){
            if (p1[i] < p2[i]) return -1;
            if (p1[i] > p2[i]) return 1;
        }
        return 0;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,5,4,7};
    string v1 = "0.1";
    string v2 = "1.0.0";
    auto r = s1.compareVersion(v1, v2);
    cout << r << endl;
}
