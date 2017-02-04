#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    // 1. Two Sum
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;
        unordered_map<int,int> mapping;
        for(int i=0;i<nums.size();i++){
            if(mapping.find(target-nums[i]) == mapping.end()){
                mapping[nums[i]] = i;
            }
            else{
                return {mapping[target-nums[i]], i};
            }
        }
        return result;
    }
};

int main()
{

    Solution s1;
    s1.twoSum();
    return 0;
}
