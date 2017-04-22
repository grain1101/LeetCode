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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    // 189. Rotate Array
    void rotateSub(vector<int>& nums, int p, int q){
        while(p < q){
            swap(nums[p++], nums[q--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rotateSub(nums, 0, n - k - 1);
        rotateSub(nums, n - k, n - 1);
        rotateSub(nums, 0, n - 1);
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    s1.rotate(nums, 2);
    showV(nums);
    //return ans;
}
