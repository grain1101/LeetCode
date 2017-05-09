#include "leetcode.h"

class Solution {
public:
    // 313. Super Ugly Number
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<long long> ret;
        ret.insert(1);
        sort(primes.begin(), primes.end());
        for(int i = 0; i < n - 1; i++){
            int tmp = *ret.begin();
            for(auto p : primes){
                if (tmp * 1ll * p > INT_MAX) break;
                ret.insert(tmp * 1ll * p);
            }
            ret.erase(tmp);
        }
        return *ret.begin();
    }
};


int main() {
    Solution s1;
    vector<int> nums = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    int n = 100000;
    auto ans = s1.nthSuperUglyNumber(n, nums);
    cout << ans << endl;
//    showV(ans);
    //show(ans);
    //showV(ans);
}
