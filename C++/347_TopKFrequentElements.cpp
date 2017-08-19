#include "leetcode.h"

// 347. Top K Frequent Elements
class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        for(auto n : nums){
            mapping[n]++;
        }
        vector<int> ret;
        priority_queue<PII> pq;
        for(auto it = mapping.begin(); it!=mapping.end();it++){
            pq.push({it->second, it->first});
        }
        for(int i = 0; i < k; i++){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

int main() {
    Solution s1;
    string s = "leetcode";
    vector<int> nums = {1,2,3,1,2,1};
    int k = 2;
    auto ans = s1.topKFrequent(nums, k);
    showV(ans);
    //cout << ans << endl;
}
