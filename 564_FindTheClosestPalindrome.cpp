#include "leetcode.h"

// 564. Find the Closest Palindrome
// if s is palindrome /*999 || 1001*/ compare half+1, half-1;
class Solution {
public:
    string nearestPalindromic(string s) {
        if (s.size() < 2) {
            s[0]--;
            return s;
        }
        string half_s = s.substr(0, (s.size() + 1) / 2);
        long long half = stoi(half_s);
        vector<long long> rets(3);
        int even = (s.size() + 1) % 2;
        for(int i = -1; i <= 1; i++){
            rets[i + 1] = getPalindrome(half + i, s.size() / 2);
        }
        int j = 0;
        long long num = stoll(s);
        for(int i = 1; i < 3; i++){
            if (abs(rets[i] - num) > 0 && abs(rets[i] - num) < abs(rets[j] - num)) j = i;
        }
        return to_string(rets[j]);
    }
private:
    bool isParlindrome(const string& s){
        string revs = s;
        reverse(revs.begin(), revs.end());
        return s == revs;
    }
    long long getPalindrome(long long seed, int n){
        string tmp = to_string(seed);
        if (tmp.size() < n || tmp == "0") tmp.push_back('9'),n--;
        string ret = tmp;
        for(int i = n - 1; i >=0; i--)
            ret.push_back(tmp[i]);
        //cout << seed << " " << ret << endl;
        return stoll(ret);
    }
};


int main() {
    Solution s1;
    string n = "100";
    auto ans = s1.nearestPalindromic(n);
    //showV(ans);
    cout << ans << endl;
}
