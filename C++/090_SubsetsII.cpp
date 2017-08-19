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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 90. Subsets II
    void dfs(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int level){
        for(int i = level; i < nums.size(); i++){
            if (i != level && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            ans.push_back(path);
            dfs(nums, ans, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        // sort nums firstly
        sort(nums.begin(), nums.end());
        ans.push_back(path);
        dfs(nums, ans, path, 0);
        return ans;
    }
};


int main() {
    vector<int> nums = {1,2,2,2};

    Solution s1;
    auto result =  s1.subsetsWithDup(nums);
    show(result);
}
