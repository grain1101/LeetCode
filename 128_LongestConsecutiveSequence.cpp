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
#include <set>
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
        cout << r;
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    //128. Longest Consecutive Sequence
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        for(auto x : nums) {
            if (left.find(x) != left.end()) continue;
            if (right.find(x) != right.end()) continue;
            int nleft = x;
            if (left.find(x - 1) != left.end()) {
                nleft = left[x - 1];
            }
            int nright = x;
            if (right.find(x + 1) != right.end()) {
                nright = right[x + 1];
            }
            //left.erase(x - 1);
            //right.erase(x + 1);
            cout << "["<<nleft << " " << nright << "]: " << x << endl;
            if (left.find(nright) != left.end()) {
                left[nright] = min(nleft, left[nright]);
            } else {
                left[nright] = nleft;
            }
            if (right.find(nleft) != right.end()) {
                right[nleft] = max(right[nleft], nright);
            } else {
                right[nleft] = nright;
            }
        }
        int ans = 0;
        for(auto &p : left) {
            ans = max(ans, p.first - p.second + 1);
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<string> ss = {"hot","dot","dog","lot","log","cog"};
    //auto result = s1.findLadders("hit","cog",ss);
    vector<int> v = {4,2,2,-4,0,-2,4,-3,-4,-4,-5,1,4,-9,5,0,6,-8,-1,-3,6,5,-8,-1,-5,-1,2,-9,1};
    cout << Solution().longestConsecutive(v) << endl;
    //show(result);
}
