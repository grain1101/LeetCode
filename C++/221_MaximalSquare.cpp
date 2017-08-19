#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
#include<list>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r << " ";
    cout << endl;
}

class Solution {
public:
    // 221. Maximal Square
    // same as 85
    int calc(vector<int>& h) {
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
            //ret = max(h[i], ret);
            int tmp = min(h[i], right[i] - left[i] + 1);
            ret = max(ret, tmp);
        }
        return ret;
    }
    // 221. Maximal Square
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        vector<int> height(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            ans = max(ans, calc(height));
        }
        return ans * ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {-2147483648,-2147483647};
    auto ans = s1.maximalSquare();
    cout << ans << endl;
    //show(ans);
    //showV(ans);
}
