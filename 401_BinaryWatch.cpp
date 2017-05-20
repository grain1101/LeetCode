#include "leetcode.h"

// 401. Binary Watch
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        ret.clear();
        if (num < 0 || num > 10) return ret;
        // 1. build hours and minutes
        hours.assign(5, vector<string>());
        minutes.assign(7, vector<string>());
        for(int i = 0; i < 12; i++){
            hours[__builtin_popcount(i)].push_back(to_string(i));
        }
        for(int i = 0; i < 60; i++){
            string tmp = to_string(i);
            if (tmp.size() != 2){
                tmp = "0" + tmp;
            }
            minutes[__builtin_popcount(i)].push_back(tmp);
        }
        // 2. find pairs

        for(int i = 0; i <= num; i++){
            int h = i, m = num - i;
            if (h > 4 || m < 0 || m > 6) continue;
            ones.push_back({h, m});
        }

        // 3. return
        for(int i = 0; i < ones.size(); i++){
            for(int j = 0; j < hours[ones[i].first].size(); j++){
                for(int k = 0; k < minutes[ones[i].second].size(); k++){
                    string tmp = hours[ones[i].first][j] + ":" + minutes[ones[i].second][k];
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
private:
    vector<string> ret;
    vector<vector<string>> hours;   // hours[i]: which hour has 'i' ones
    vector<vector<string>> minutes;
    vector<pair<int,int>> ones;
};

int main() {
    Solution s1;
    int num = -3;
    auto ans = s1.toHex(num);
    cout << ans << endl;
}
