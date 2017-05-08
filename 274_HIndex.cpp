#include "leetcode.h"
class Solution {
public:
    // 274. H-Index
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        countSort(citations);
        //showV(citations);
        int n = citations.size();
        int ret = 0;
        for(int i = n; i >=0; i--){
            if (citations[n - i] >= i && citations[n - i - 1] <= i){
                ret = i;
                break;
            }
        }
        return ret;
    }
    void countSort(vector<int>& citations){
        int n = citations.size();
        vector<int> cnts(n+1, 0);
        for(int i = 0; i < n; i++){
            if (citations[i] >= n) cnts[n]++;
            else cnts[citations[i]]++;
        }
        int j = 0;
        for(int i = 0; i <= n; i++){
            for(int k = 0; k < cnts[i]; k++){
                citations[j++] = i;
            }
        }
    }
};
int main() {
    Solution s1;
    vector<int> nums = {12};
    auto ans = s1.hIndex(nums);
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
