#include "leetcode.h"

class Solution {
public:
    // 282. Expression Add Operators
    void dfs(vector<string>& ret, string num, int target, string path, long long last, long long sum){
        if (num.size() == 0){
            if (sum == target) {
                ret.push_back(path);
                return;
            }
        }
        for(int i = 1; i <= num.size(); i++){
            string cur = num.substr(0, i);
            if (cur.size() > 1 && cur[0] == '0') return;

            string nextNum = num.substr(i);
            long long subValue = stoll(cur);
            //cout << "cur:" << cur << " subValue:" << subValue << " sum:" << sum << endl;
            if (path.size() > 0){
                dfs(ret, nextNum, target, path + "+" + cur, subValue, sum + subValue);
                dfs(ret, nextNum, target, path + "-" + cur, -subValue, sum - subValue);
                dfs(ret, nextNum, target, path + "*" + cur, last * subValue, (sum - last) + (last * subValue));
            }
            else {
                dfs(ret, nextNum, target, cur, subValue, subValue);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        dfs(ret, num, target, "", 0, 0);
        return ret;
    }
};

int main() {
    Solution s1;
    string nums = "00";
    int target = 0;
    auto ans = s1.addOperators(nums, target);
    showV(ans);
    //show(ans);
    //showV(ans);
}
