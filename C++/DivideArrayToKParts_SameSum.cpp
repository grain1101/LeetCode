#include "leetcode.h"

/**
Mock Interview
Problem: Divide Array
    give you an array and a k, determine whether this array can divide into k part,
    each part's sum are same.

Solution:
    if array's sum can not be divisible, return false. otherwise the subsum = sum / k;

Similar Problem: LeetCode 548. Split Array with Equal Sum
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int> _nums, int _k){
        nums = _nums;
        k = _k;
        ret.clear();
        visited.assign(nums.size(), false);
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (sum % k != 0 || k > nums.size()) return ret;
        target = sum / k;
        vector<int> path;
        dfs(0, path);
        if (ret.size() != k) {
            ret.clear();
            return ret;
        }
        int leftsum = 0;
        for(int i = 0; i < nums.size(); i++) if(!visited[i]) leftsum += nums[i];
        if (leftsum == 0) {
            for(int i = 0; i < nums.size(); i++) if(!visited[i]) ret[0].push_back(nums[i]);
        }
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> visited;
    vector<int> nums;

    int k;
    int target;
    bool dfs(int tempSum, vector<int>& path){
        //cout << tempSum << " : ";
        //for(int i = 0; i < nums.size(); i++) if(!visited[i]) cout << nums[i] << ' '; cout << endl;

        if (path.size() && tempSum == target){
            ret.push_back(path);
            path.clear();
            tempSum = 0;
        }

        //cout << "ret.size " << ret.size() << endl;
        if (ret.size() == k) return true;
        for(int i = 0; i < nums.size(); i++){
            if (visited[i] == false){
                visited[i] = true;
                path.push_back(nums[i]);
                if (dfs(tempSum + nums[i], path)) return true;
                path.pop_back();
                visited[i] = false;
            }
        }
        return false;
    }
};

int main() {
    Solution s1;

    vector<int> nums1 = {4,3,2,3,5,2,1};
    vector<int> nums2 = {0,0,0,0};
    vector<int> nums3 = {2,-2,2,-2, 2, -2};
    vector<vector<int>> nums = {{3,3,3,3},{2,-2,2,-2, 2, -2}};
    vector<int> ks = {4,2};
    auto ans = s1.divideArray(nums[1], ks[1]);
    show(ans);
}
