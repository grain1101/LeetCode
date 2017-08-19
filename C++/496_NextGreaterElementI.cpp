#include "leetcode.h"

// 496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret(findNums.size());
        unordered_map<int, int> m;
        stack<int> st;
        for(auto n : nums){
            while(!st.empty() && st.top() < n){
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        int i = 0;
        for(auto n : findNums){
            int tmp = m.find(n)==m.end() ? -1 : m[n];
            ret[i++] = tmp;
        }
        return ret;
    }
};


int main() {
    Solution s1;
    auto ans = s1.hammingDistance(1,4);
    //showV(ans);
    cout << ans << endl;
}
