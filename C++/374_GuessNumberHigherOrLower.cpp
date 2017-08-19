#include "leetcode.h"

// 374. Guess Number Higher or Lower
int guess(int num);
int guess(int num){
    if (num == 6) return 0;
    if (num > 6) return -1;
    if (num < 6) return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        if (guess(0) == 0) return 0;
        if (guess(n) == 0) return n;
        while(1){
            int mid = l + (r - l) / 2;
            int tmp = guess(mid);
            if (tmp == 0) return mid;
            if (tmp == 1) l = mid;
            if (tmp == -1) r = mid;
        }
    }
};

int main() {
    Solution s1;
    auto ans = s1.guessNumber(7);
    cout << ans << endl;
}
