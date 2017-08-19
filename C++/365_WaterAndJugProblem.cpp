#include "leetcode.h"

// 365. Water and Jug Problem
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (x == 0) return y == z;
        if (y == 0) return x == z;
        if (x + y < z) return false;
        int d = gcd(x, y);
        return z % d == 0;
    }

    bool canMeasureWater_dp(int x, int y, int z) {
        dp.clear();
        this->x = x;
        this->y = y;
        this->z = z;
        dfs(0,0);
        for(const auto& p : dp){
            printf("[%d, %d]\n", p.first, p.second);
            //if (p.first == z || p.second == z || p.first + p.second == z) return true;
        }
        return false;
    }
private:
    int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
    set<pair<int, int>> dp;
    int x, y, z;
    void dfs(int a, int b){
        pair<int, int> ab(a,b);
        if (dp.find(ab) != dp.end()) return;
        dp.insert(ab);
        //if (a == z || b == z || a + b == z) return ;
        // 1. empty A
        dfs(0, b);
        // 2. empty B
        dfs(a, 0);
        // 3. fill A to full
        dfs(x, b);
        // 4. fill B to full
        dfs(a, y);
        // 5. pour A to B
        int pour = min(a, y - b);
        dfs(a-pour, b + pour);
        // 6. pour B to A
        pour = min(b, x - a);
        dfs(a + pour, b - pour);
    }
};



int main() {
    Solution s1;
    auto ans = s1.canMeasureWater(10, 6, 1);
    //showV(ans);
    cout << ans << endl;
}
