#include "leetcode.h"
// Merge Sort
//void mergeSort(vector<int>& nums, int l, int r){
//    //cout << l << " " << r << endl;
//    if (l >= r) return;
//    int pivot = l + (r - l) / 2;
//    mergeSort(nums, l, pivot);
//    mergeSort(nums, pivot + 1, r);
//    vector<int> tmp(r - l + 1);
//    int t = 0, i = l, j = pivot + 1;
//    while(i <= pivot && j <= r){
//        if (nums[i] < nums[j]){
//            tmp[t++] = nums[i++];
//
//        } else {
//            tmp[t++] = nums[j++];
//        }
//    }
//    while(i <= pivot) tmp[t++] = nums[i++];
//    while(j <= r) tmp[t++] = nums[j++];
//    t = 0, i = l;
//    while(t < tmp.size()){
//        nums[l++] = tmp[t++];
//    }
//}

typedef pair<int,int> PII;
class Solution {
public:
    // 315. Count of Smaller Numbers After Self
    vector<int> countSmaller(vector<int>& nums) {
        vector<PII> numIndex(nums.size());
        ret.assign(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            numIndex[i].first = nums[i];
            numIndex[i].second = i;
        }
        mergeSort(numIndex, 0, nums.size() - 1);
        return ret;
    }
    void mergeSort(vector<PII>& nums, int l, int r){
        if (l >= r) return;
        int pivot = l + (r - l) / 2;
        mergeSort(nums, l, pivot);
        mergeSort(nums, pivot + 1, r);
        vector<PII> tmp(r - l + 1);
        int t = 0, i = l, j = pivot + 1;
        while(i <= pivot && j <= r){
            if (nums[i].first <= nums[j].first){
                ret[nums[i].second] += j - pivot - 1;
                tmp[t++] = nums[i++];

            } else {
                tmp[t++] = nums[j++];
            }
        }
        while(i <= pivot){
            ret[nums[i].second] += j - pivot - 1;
            tmp[t++] = nums[i++];
        }
        while(j <= r){
            tmp[t++] = nums[j++];
        }
        t = 0, i = l;
        while(t < tmp.size()){
            nums[i++] = tmp[t++];
        }
    }
private:
    vector<int> ret;
};


int main() {
    Solution s1;
    vector<int> nums = {2,0,1};
    auto ans = s1.countSmaller(nums);
//    cout << ans << endl;
    showV(ans);
    //show(ans);
    //showV(ans);
}
