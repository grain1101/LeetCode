#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 15. 3Sum
    // input: S = [-1, 0, 1, 2, -1, -4],
    // output: [[-1, 0, 1], [-1, -1, 2]]
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(l-1>i && nums[l]==nums[l-1]){
                    l++;
                    continue;
                }
                if(r+1<nums.size() && nums[r]==nums[r+1]){
                    r--;
                    continue;
                }
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                }
                if(sum>0) r--;
                if(sum<0) l++;
            }
        }
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {0, 0, 0, 0};
    string s = "IV";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};

    // 2. Run
    Solution s1;
    auto result = s1.threeSum(nums);

    // 3. Compare output
    for(auto n : result){
        for(auto num : n){
            cout << num << " ";
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
