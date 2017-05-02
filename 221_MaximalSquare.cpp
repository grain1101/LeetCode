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

struct SwapLine{
    int x;
    int y;
    bool in;
    SwapLine(int X, int Y, bool In): x(X), y(Y), in(In){};
    bool operator<(const SwapLine& a) const {
        if (a.x != x) return x < a.x;
        if (a.y != y) return y < a.y;
        return a.in < in;
    }
    void show(){
        cout << x << " " << y << " " << in << endl;
    }
};
class Solution {
public:
    // 221. Maximal Square
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound(nums[i] * 1ll - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            // x - nums[i] <= t ==> |x - nums[i]| <= t
            if (pos != window.end() && *pos*1ll - nums[i]*1ll <= t * 1ll) return true;
            window.insert(nums[i] * 1ll);
        }
        return false;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {-2147483648,-2147483647};
    auto ans = s1.containsNearbyAlmostDuplicate(nums,3,3);
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
