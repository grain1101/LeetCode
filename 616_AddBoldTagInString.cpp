#include "leetcode.h"

// 616. Add Bold Tag in String
// KMP
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string ret;
        vector<int> d(s.size() + 1, 0);
        for(auto tmp : dict){
            vector<int> failure(tmp.size(), -1);
            int k = 0;
            failureFunction(tmp, failure);
            int cur = -1;
            for(int i = 0; i < s.size(); i++){
                while(cur >= 0 && tmp[cur + 1] != s[i]) cur = failure[cur];
                if (tmp[cur + 1] == s[i]) cur++;
                if (cur == tmp.size() - 1){
                    cout << cur << " " << i + cur - tmp.size() << " " << i + cur << endl;
                    d[i + 1 - tmp.size()]++;
                    d[i + 1]--;
                }
            }
        }
        for(int i = 1; i < d.size(); i++){
            d[i] += d[i - 1];
        }
        for(int i = 0; i < d.size(); i++){
            if (d[i] > 0){
                int j = i;
                while(j < d.size() && d[j] > 0) j++;
                ret.append(startB);
                ret.append(s.substr(i, j - i));
                ret.append(endB);
                i = j - 1;
            }else {
                ret += s[i];
            }
        }
        showV(d);
        cout << ret << endl;
        return ret;
    }
private:
    const string startB = "<b>";
    const string endB = "</b>";
    void failureFunction(const string& s, vector<int>& fail){
        for(int i = 1, j = fail[0]= -1; i < s.size(); i++){
            while(j >=0 && s[j + 1] != s[i]) j = fail[j];
            if (s[j + 1] == s[i]) j++;
            fail[i] = j;
        }
    }
};


int main() {
    Solution s1;
    //vector<int> nums = {48,66,61,46,94,75};
    vector<int> nums = {2,2,2};
    string s = "abcxyz123";
    vector<string> dict = {"abc","123"};
    s1.addBoldTag(s, dict);
    //cout << ans << endl;
}
