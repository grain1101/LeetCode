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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 46. Permutations
    // DFS
    // [1,2,3] ->  all possible permutations
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, vector<int>& used){
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == 0){
                used[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, ans, path, used);
                path.pop_back();
                used[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        //sort(nums.begin(), nums.end());
        dfs(nums, ans, path, used);
        return ans;
    }
};

int main() {
    vector<int> nums = {1,0,5,2};
    Solution s1;
    auto result = s1.permute(nums);
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
