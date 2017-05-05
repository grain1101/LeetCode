#include "leetcode.h"
class Solution {
public:
    // 239. Sliding Window Maximum
    // max_heap, multiset
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            window.insert(nums[i]);
            if (i >= k)     window.erase(window.find(nums[i-k]));
            if (i >= k - 1) ans.push_back(*window.rbegin());
        }
        return ans;
    }

    vector<int> maxSlidingWindow_heap(vector<int>& nums, int k) {
        unordered_map<int, int> delCnts;
        priority_queue<int> heap;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            heap.push(nums[i]);
            if (i >= k) {
                delCnts[nums[i - k]]++;
                while(delCnts[heap.top()] > 0){
                    delCnts[heap.top()]--;
                    heap.pop();
                }
            }
            if (i >= k - 1) ans.push_back(heap.top());
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};

    auto ans = s1.maxSlidingWindow(nums, 3);
    //cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
