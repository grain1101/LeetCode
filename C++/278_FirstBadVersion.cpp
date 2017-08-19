#include "leetcode.h"
bool isBadVersion(int version){
    return version >= 1 ;
}

class Solution {
public:
    // 278. First Bad Version
    int binarySearch(int r){
        int l = 1;
        if (isBadVersion(l)) return l;
        if (!isBadVersion(r)) return r + 1;
        while(l + 1 < r){
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
    int firstBadVersion(int n) {
        return binarySearch(n);
    }
};


int main() {
    Solution s1;
    vector<int> nums = {12};
    auto ans = s1.firstBadVersion(2);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
