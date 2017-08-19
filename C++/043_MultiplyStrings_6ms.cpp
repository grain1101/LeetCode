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
    // 43. Multiply Strings
    string multiply(string a, string b) {
        // a = x*10^i; b = y*10^j; a*b = x*y*10^(i+j);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        vector<int> ans(a.size() + b.size(), 0);
        for(int i = 0; i < a.size(); i++){
            for(int j = 0;j < b.size(); j++){
                ans[i+j] += (a[i] - '0') * (b[j] - '0');
            }
        }
        for(int i = 0; i < ans.size() - 1; i++){
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
        // remove extra '0' from ans
        // if a[0]=0 keep it.
//        for(int i=ans.size()-1;i>0;i--){
//            if(ans[i]==0) ans.pop_back();
//        }
         for(int i = ans.size() - 1; i > 0 && ans[i] == 0; i --) {
            ans.pop_back();
        }
        string ret(ans.size(), '0');
        for(int i = ans.size() - 1; i >= 0; i --) {
            ret[ans.size() - 1 - i] += ans[i];
        }
        return ret;
    }
};

int main() {
    // 1. Input test cases
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int n = 8;
    string a = "123";
    string b = "456";
    // 2. Run
    Solution s1;
    auto result = s1.multiply(a,b);

    // 3. Compare output
//    for(auto i : result){
//        for(auto t : i)
//            cout << t << " ";
//        cout << endl;
//    }

    cout << result << endl;
    return 0;
}
