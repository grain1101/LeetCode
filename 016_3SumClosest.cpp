#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 16. 3Sum Closest
    // input: S = [-1, 2, 1, -4], 1
    // output: 2 (-1 + 2 + 1 = 2).
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_gap = INT_MAX;
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1, r = nums.size()-1;
            while(l<r){
                if(l>i+1 && nums[l]==nums[l-1]) {
                    l++;
                    continue;
                }
                if(r<nums.size()-1 && nums[r]==nums[r+1]){
                    r--;
                    continue;
                }
                int tmp = nums[i]+nums[l]+nums[r];
                int gap = abs(tmp - target);
                if(gap <= min_gap){
                    min_gap = gap;
                    result = tmp;
                }
                if(tmp < target){
                    l++;
                }
                if(tmp > target){
                    r--;
                }
                if(tmp == target){
                    return target;
                }
            }
        }
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {-1, 2, 1, -4};
    string s = "IV";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};

    // 2. Run
    Solution s1;
    auto result = s1.threeSumClosest(nums, 1);

    // 3. Compare output
//    for(auto n : result){
//        for(auto num : n){
//            cout << num << " ";
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
