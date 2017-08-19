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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 45. Jump Game II
    // Greedy; [2][3,1][1,4]
    int jump(vector<int>& nums) {
        int result = 0;
        int p = 0, q = 0;
        while (q < nums.size() - 1){
            int tmp = 0;
            for(int i=p;i<=q;i++){
                tmp = max(tmp, i + nums[i]);
            }
            p = q + 1;
            q = tmp;
            result++;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution s1;
    auto result = s1.jump(nums);
    cout << result << endl;
    return 0;
}
