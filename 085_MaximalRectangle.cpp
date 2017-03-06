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
#include <limits>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    // 85. Maximal Rectangle
    int calc(vector<int>& h) {
        // same as 084_Largest Rectangle in Histogram
        int n = h.size();
        vector<int> left(n, 0), right(n, n - 1);
        stack<int> st;
        for(int i = 0; i < n; i ++) {
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            if (!st.empty()) left[i] = st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i --) {
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            if (!st.empty()) right[i] = st.top() - 1;
            st.push(i);
        }
        int ret = 0;
        for(int i = 0; i < n; i ++) {
            ret = max(ret, h[i] * (right[i] - left[i] + 1));
        }
        return ret;
    }
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<int> height(m, 0);
        int ret = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            // because if matrix[i][j] == '0', height[j] = 0,
            // so we have to calc the ret at each j loop
            ret = max(ret, calc(height));
        }
        return ret;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    Solution s1;
    auto result = s1.largestRectangleArea(nums);
    cout << result << endl;
    return 0;
}
