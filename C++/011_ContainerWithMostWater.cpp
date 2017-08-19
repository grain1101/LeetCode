#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 11. Container With Most Water
    // greedy
    int maxArea(vector<int>& height) {
        int p=0, q = height.size()-1;
        int result = 0;
        while(p<=q){
            int tmp = (q-p) * min(height[p], height[q]);
            result = max(result, tmp);
            if(height[p]<height[q]){
                p++;
            } else{
                q--;
            }
        }
        return result;
    }
};

int main()
{
    // 1. Input test cases
    int num = 1001;
    vector<int> nums = {3,2,1,3};
    string ss1 = "abbc";
    string ss2 = "ab*bbc";

    // 2. Run
    Solution s1;
    auto result = s1.maxArea(nums);

    // 3. Compare output

    cout << result << endl;
    return 0;
}
