#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 31. Next Permutation
    // Input:  (1,2,3); (3,2,1)
    // Output: (1,3,2); (1,2,3)
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i= len - 1;
        for(;i>=0;i--){
            if(i<len-1 && nums[i] < nums[i+1]) {
                int tmp = i+1;
                int j=i+1;
                while(j<len){
                    if(nums[j] >  nums[i] && nums[j] < nums[tmp]){
                        tmp = j;
                    }
                    j++;
                }
                swap(nums[i], nums[tmp]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        if (i==-1) {
            for(int i=0;i<len/2;i++){
                swap(nums[i], nums[len-1-i]);
            }
        }
        return;
    }
};

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1,2,4,3,1};
    string s = "()[[]{}";
//    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;

    // 2. Run
    Solution s1;
    s1.nextPermutation(nums);
    auto result = nums;
    // 3. Compare output
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
//    cout << result << endl;
    return 0;
}
