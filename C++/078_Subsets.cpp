#include "leetcode.h"

// 78. Subsets
class Solution {
public:
    //recursive
    vector<vector<int>> subsets_dfs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> path;
        dfs(0,nums, path, ret);
        return ret;
    }
    // iterative
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret(1, vector<int>());
        for(int i = 0; i < nums.size(); i++){
            int n = ret.size();
            for(int j = 0; j < n; j++){
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
private:
    void dfs(int level, vector<int>& nums, vector<int>& path, vector<vector<int>>& ret){
        ret.push_back(path);
        for(int i = level; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(i + 1, nums, path, ret);
            path.pop_back();
        }
    }
};

int main() {
    Solution s1;
    //vector<int> nums = {48,66,61,46,94,75};
    vector<int> nums = {1,2,3};
    auto ans = s1.subsets(nums);
    //cout << ans << endl;
}
