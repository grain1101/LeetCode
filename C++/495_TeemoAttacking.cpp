#include "leetcode.h"

// 495. Teemo Attacking
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0;
        for(int i = 0; i < timeSeries.size(); i++) {
            if (i + 1 < timeSeries.size())
                ret += min(timeSeries[i + 1] - timeSeries[i],  duration);
            else ret += duration ;
        }
        return ret;
    }
};


int main() {
    Solution s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
