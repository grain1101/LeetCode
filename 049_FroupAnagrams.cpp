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
    // 49. Group Anagrams
    // ["eat", "tea", "tan", "ate", "nat", "bat"]
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> str2idx;
        int index = 0;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (str2idx.find(tmp) == str2idx.end()){
                str2idx[tmp] = index++;
                ans.push_back({});
            }
            ans[str2idx[tmp]].push_back(strs[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.permuteUnique(nums);
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
//    cout << result << endl;
    return 0;
}
