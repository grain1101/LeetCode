#include "leetcode.h"

class Solution {
public:
    // 299. Bulls and Cows
    string getHint(string secret, string guess) {
        vector<int> d1(10, 0);
        vector<int> d2(10, 0);
        for(int i = 0; i < secret.size(); i++){
            d1[secret[i]-'0']++;
            d2[guess[i] - '0']++;
        }
        int a = 0, b = 0;
        for(int i = 0; i < secret.size(); i++){
            if (secret[i] == guess[i]) a++;
        }
        for(int i = 0; i < 10; i++){
            b += min(d1[i], d2[i]);
        }
        b -= a;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};

int main() {
    Solution s1;
    string secret = "1807";
    string guess = "7810";
    auto ans = s1.getHint(secret, guess);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
