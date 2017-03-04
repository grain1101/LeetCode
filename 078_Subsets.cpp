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
    // 78. Subsets
    void dfs(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int level){
        for(int i = level; i < nums.size(); i++){
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(result, path, nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        result.push_back(path);
        dfs(result, path, nums, 0);
        return result;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution s1;
    auto result = s1.subsets(nums);
    show(result);
    cout << result.size() << endl;
    return 0;
}
