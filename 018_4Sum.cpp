#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 18. 4Sum
    // input: {1, 0, -1, 0, -2, 2}; 0
    // output: {{-1,  0, 0, 1}, {-2, -1, 1, 2}, {-2,  0, 0, 2}}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int tmp = target-nums[i];
            for(int j=i+1;j<len;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1, r = len-1;
                while(l<r){
                    if(l>j+1 && nums[l]==nums[l-1]){
                        l++;
                        continue;
                    }
                    if(r<len-1 && nums[r]==nums[r+1]){
                        r--;
                        continue;
                    }
                    int sum = nums[j]+nums[l]+nums[r];
                    if(sum==tmp){
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                    }
                    if(sum<tmp){
                        l++;
                    }
                    if(sum>tmp){
                        r--;
                    }
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
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    string s = "23";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};

    // 2. Run
    Solution s1;
    auto result = s1.fourSum(nums, 0);

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
