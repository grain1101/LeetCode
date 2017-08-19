#include "leetcode.h"

// 593. Valid Square
class Solution {
public:
    typedef pair<int, int> PII;
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> len(6);
        int i = 0;
        len[i++] = getDistance(p1[0], p1[1], p2[0], p2[1]);
        len[i++] = getDistance(p2[0], p2[1], p3[0], p3[1]);
        len[i++] = getDistance(p3[0], p3[1], p4[0], p4[1]);
        len[i++] = getDistance(p4[0], p4[1], p1[0], p1[1]);
        len[i++] = getDistance(p1[0], p1[1], p3[0], p3[1]);
        len[i++] = getDistance(p2[0], p2[1], p4[0], p4[1]);
        sort(len.begin(), len.end());
        //showV(len);
        if (len[0] == len[1] && len[0] == len[2] && len[0] == len[3] && len[0] > 0 &&
            len[0] + len[2] == len[4] && len[4] == len[5] && len[4] > 0) return true;
        return false;
    }
    long long getDistance(int x1, int y1, int x2, int y2){
        return abs(x1 - x2)* abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
    }
};

int main() {
    Solution s1;
    vector<int> p1 = {1,0};
    vector<int> p2 = {-1,0};
    vector<int> p3 = {0,1};
    vector<int> p4 = {0,-1};
    auto ans = s1.validSquare(p1, p2, p3, p4);
    cout << ans << endl;
}
