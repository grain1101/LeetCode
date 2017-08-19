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
#include <string>
#include<list>
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

struct SwapLine{
    int x;
    int y;
    bool in;
    SwapLine(int X, int Y, bool In): x(X), y(Y), in(In){};
    bool operator<(const SwapLine& a) const {
        if (a.x != x) return x < a.x;
        if (a.y != y) return y < a.y;
        return a.in < in;
    }
    void show(){
        cout << x << " " << y << " " << in << endl;
    }
};
class Solution {
public:
    // 218. The Skyline Problem
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        vector<SwapLine> swapLineVec;
        for(int i = 0; i < buildings.size(); i++){
            swapLineVec.push_back(SwapLine(buildings[i][0], buildings[i][2], true));
            swapLineVec.push_back(SwapLine(buildings[i][1], buildings[i][2], false));
        }
        sort(swapLineVec.begin(), swapLineVec.end());
//        for(auto a : swapLineVec){
//            a.show();
//        }
        multiset<int> height;
        height.insert(0);
        for(int i = 0; i < swapLineVec.size(); i++){
            //int maxHeight = *height.rbegin();
            auto it = height.end();
            it--;
            int maxHeight = *it;
            int j = i;
            while(j < swapLineVec.size() && swapLineVec[i].x == swapLineVec[j].x) j++;
            for(int k = i; k < j; k++) {
                if (swapLineVec[k].in) height.insert(swapLineVec[k].y);
                else height.erase(height.find(swapLineVec[k].y));
            }
            int newMaxHeight = *height.rbegin();
            if (maxHeight != newMaxHeight) {
                ans.push_back(pair<int, int>(swapLineVec[i].x, newMaxHeight));
            }
            i = j - 1;
            // for(auto h : height) cout << h << " "; cout << " height " << i << "\n";
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {0,1,2,3};
    // [[0,2,3],[2,4,3],[4,6,3]]
    vector<vector<int>> buildings1 = {{0,2,3},{2,4,3},{4,6,3}};
    auto ans = s1.getSkyline(buildings1);
    for(auto a : ans){
        cout << a.first << " " << a.second<< endl;
    }
    //cout << ans << endl;
    //show(ans);
    //showV(ans);
}
