#include "leetcode.h"

// 492. Construct the Rectangle
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int m = sqrt(area);
        int l = area / m;
        while(area % m != 0){
            m--;
            l = area / m;
        }
        return {l, m};
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
