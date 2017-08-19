#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

class Solution {
  public:
    // 77. Combinations
    void dfs(vector<vector<int>>& result, vector<int>& path, int n, int k, int num){
        if (path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = num; i <= n; i++){
            path.push_back(i);
            dfs(result, path, n, k, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(result, path, n, k, 1);
        return result;
    }
};

int main() {
    Solution s1;
    auto result = s1.combine(4,2);
    show(result);
    cout << endl;
    return 0;
}
