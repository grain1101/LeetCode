#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 39. Combination Sum
    void dfs(vector<vector<int>>& result, vector<int>& c, vector<int>& tmp, int target, int level, int sum){
        if (sum == target) {
            result.push_back(tmp);
            return;
        }
        for(int i=level;i<c.size();i++){
            if (c[i] <= target - sum) {
                tmp.push_back(c[i]);
                dfs(result, c, tmp, target, i, sum + c[i]);
                tmp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        if (c.size() == 0) return {};
        sort(c.begin(), c.end());
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result, c, tmp, target, 0, 0);
        return result;
    }
};

int main() {
    // 1. Input test cases
    vector<int> nums = {2,3,6,7};
    int n = 7;
    // 2. Run
    Solution s1;
    auto result = s1.combinationSum(nums, n);

    // 3. Compare output
    for(auto i : result){
        for(auto t : i)
            cout << t << " ";
        cout << endl;
    }

//    cout << result << endl;
    return 0;
}
