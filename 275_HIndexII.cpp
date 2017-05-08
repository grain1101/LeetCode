#include "leetcode.h"
class Solution {
public:
    // 275. H-Index II
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int n = citations.size(), ret = 0;
        for(int i = n; i >=0; i--){
            if (citations[n - i] >= i && citations[n - i - 1] <= i){
                ret = i;
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,1,2};
    auto ans = s1.hIndex(nums);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
