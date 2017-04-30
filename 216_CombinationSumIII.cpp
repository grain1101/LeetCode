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

class Solution {
public:
    // 216. Combination Sum III
    void dfs(int k, int n, vector<int> &path, int& sum, int idx){
        if (path.size() == k && sum == n){
            ans.insert(path);
            return;
        }
        if (path.size() > k || sum > n) return ;
        path.push_back(idx);
        sum += idx;
        for(int i = idx; i <=9; i++){
            dfs(k,n,path,sum, i + 1);
        }
        sum -= idx;
        path.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n <= 0 || k == 0) return {};
        vector<int> path;

        for(int i = 1; i <= 9; i++){
            int sum = 0;
            dfs(k,n,path, sum, i);
        }
        for(auto s : ans){
            ret.push_back(s);
        }
        return ret;
    }
private:
    set<vector<int>> ans;
    vector<vector<int>> ret;
};

int main() {
    Solution s1;
    vector<int> nums = {1,0,-1};
    int k = 0;
    auto ans = s1.combinationSum3(3,7);
    //cout << ans << endl;
    show(ans);
    //showV(ans);
}
