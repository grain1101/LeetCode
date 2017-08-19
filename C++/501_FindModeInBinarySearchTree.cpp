#include "leetcode.h"

// 501. Find Mode in Binary Search Tree
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        int maxCnt = 0;
        for(int i = 0; i < cnt.size(); i++){
            int j = i;
            while(j < cnt.size() && cnt[j] == cnt[i]) j++;
            maxCnt = max(maxCnt, j - i);
            i = j - 1;
        }
        vector<int> ret;
        for(int i = 0; i < cnt.size(); i++){
            int j = i;
            while(j < cnt.size() && cnt[j] == cnt[i]) j++;
            if (j - i == maxCnt) ret.push_back(cnt[i]);
            i = j - 1;
        }
        return ret;
    }
private:
    vector<int> cnt;
    void inOrder(TreeNode* root){
        if (root == nullptr) return;
        inOrder(root->left);
        cnt.push_back(root->val);
        inOrder(root->right);
    }
};


int main() {
    Solution2 s1;
    string s = "abab";
    auto ans = s1.repeatedSubstringPattern("abadabad");
    cout << ans << endl;

    int i = 0, j = 0;
}
