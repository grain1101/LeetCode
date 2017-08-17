// 464. Can I Win
// 100++
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    bool canWin(int length, int total, int used, unordered_map<int, bool>& m) {
        if (m.count(used)) return m[used];
        for (int i = 0; i < length; ++i) {
            int cur = (1 << i);
            if ((cur & used) == 0) {
                if (total <= i + 1 || !canWin(length, total - (i + 1), cur | used, m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
    // this much faster than I
    bool canIWinII(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger*(1 + maxChoosableInteger) / 2 < desiredTotal) return false;
        maxSteps = maxChoosableInteger;
        desired = desiredTotal;
        dp.assign((1<<maxSteps), -1);
        return !isP(0);        
    }
private:
    int isP(int status) {
        if (dp[status] != -1) return dp[status];
        int &ret = dp[status];
        ret = 0;
        int sum = 0;
        for(int i = 0; i < maxSteps; i++) {
            if (status & (1<<i))sum += (i+1);
        }
        if (sum >= desired) return ret = 1;
        for(int i = 0; i < maxSteps; i++) {
            if (status & (1<<i)) continue;
            if (isP(status | (1<<i))) return ret = 0;
        }
        return ret = 1;
    }
    int maxSteps;
    int desired;
    vector<int> dp;
};