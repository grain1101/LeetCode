#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
#include<list>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}

class Solution {
public:
    // 229. Majority Element II
    vector<int> majorityElement(vector<int>& nums) {
        int major1, major2, counts1 = 0, counts2 = 0, n = nums.size();
        for(auto n : nums){
            if (major1 == n) counts1++;
            else if (major2 == n) counts2++;
            else if (!counts1){
                major1 = n;
                counts1 = 1;
            }
            else if (!counts2){
                major2 = n;
                counts2 = 1;
            }
            else {
                counts1--;
                counts2--;
            }
        }
        counts1 = 0, counts2 = 0;
        for(auto n : nums){
            if (n == major1) counts1++;
            else if (n == major2) counts2++;
        }
        vector<int> ret;
        if (counts1 > n / 3) ret.push_back(major1);
        if (counts2 > n / 3) ret.push_back(major2);
        return ret;
    }
    // 169. Majority Element
    int majorityElementI(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            cout << "i:" << i << " num:" << nums[i] << " major:" << major << " counts:" << counts << endl;
            if (!counts){
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major)? 1 : -1;
        }
        return major;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {-1,2,5,3,3,3,1,3};
    auto ans = s1.majorityElement(nums);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
