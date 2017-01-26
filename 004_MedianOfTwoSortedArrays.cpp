#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
public:
    // 4. Median of Two Sorted Arrays
    // Input: (1,3)(2); (1,2)(3,4);
    // Output: 2.0; (2 + 3)/2 = 2.5;
    int findKth(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2, int e2, int k){
        // index = k
        // s1,e1,s2,e2,k are all index.
        if(e1 - s1 > e2 - s2) return findKth(nums2, s2, e2, nums1, s1, e1, k);
        if(e1 - s1 + 1 == 0) return nums2[s2+k];
        if(k==0) return min(nums1[s1], nums2[s2]);
        int p1, p2;
        // p1,p2 are index too.
        p1 = min(k/2, e1 - s1);
        p2 = k - p1 - 1;
        if(nums1[s1+p1] < nums2[s2+p2]){
            return findKth(nums1, s1+p1+1, e1, nums2, s2, e2, k-p1-1);
        }
        if(nums1[s1+p1] > nums2[s2+p2]){
            return findKth(nums1, s1, e1, nums2, s2+p2+1, e2, k-p2-1);
        }
        return nums1[s1+p1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if((len1 + len2)%2){
            return 1.0 * findKth(nums1, 0, len1-1, nums2, 0, len2-1, (len1+len2)/2 );
        }
        else{
            return 0.5 * (findKth(nums1, 0, len1-1, nums2, 0, len2-1, (len1+len2)/2) + findKth(nums1, 0, len1-1, nums2, 0, len2-1, (len1+len2)/2 - 1));
        }
    }
};

int main()
{
    // 1. Input test cases
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    // 2. Run
    Solution s1;
    double result = s1.findMedianSortedArrays(nums1, nums2);

    // 3. Compare output
    cout << result << endl;
    return 0;
}
