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
  public:
    // 84. Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> height) {
        if (height.size() == 0) return 0;
        // left[i]: from left to right, the first value(height[left[i]]) >= height[i]
        // right[i]: from right to left, the first value(height[right[i]]) >= height[i]
        // stack st: 单调递增栈。
        vector<int> left(height.size()), right(height.size());
        stack<int> st;
        // fill in left array
        for(int i = 0; i < height.size(); i++){
            while(st.size() && height[st.top()] >= height[i]) st.pop();
            left[i] = st.size() ? st.top() + 1 : 0;
            st.push(i);
        }
        // clear stack st
        while(st.size()) st.pop();
        // fill in right array
        for(int i = height.size() - 1; i >= 0; i--){
            while(st.size() && height[st.top()] >= height[i]) st.pop();
            right[i] = st.size() ? st.top() - 1 : height.size() - 1;
            st.push(i);
        }
        // calculate largest rectangle
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            ans = max(ans, height[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    Solution s1;
    auto result = s1.largestRectangleArea(nums);
    cout << result << endl;
    return 0;
}
