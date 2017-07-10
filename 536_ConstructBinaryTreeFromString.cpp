#include "leetcode.h"

typedef pair<int, int> PII;
class Solution {
public:
    // 536 Construct Binary Tree from String
    TreeNode* str2tree(string s) {
        if (s.size() == 0) return nullptr;
        int flag = 1;
        stack<TreeNode*> st;
        int tmp = 0;
        TreeNode* root = nullptr;
        for(int i = 0; i < s.size(); i++){
            //cout << i << endl;
            if (s[i] == '-') flag = -1;
            else if (isdigit(s[i])) {
                while(i < s.size() && isdigit(s[i]))
                    tmp = tmp * 10 + s[i++] - '0';
                TreeNode* cur = new TreeNode(tmp * flag);
                tmp = 0;
                flag = 1;
                st.push(cur);
                if (root == nullptr) {
                    root = cur;
                }
                i--;
            }else {
                if (s[i] == ')'){
                    TreeNode* cur = st.top();
                    st.pop();
                    if (st.empty()) break;
                    if (st.top()->left == nullptr) st.top()->left = cur;
                    else  st.top()->right = cur;
                }
            }
        }
        //cout << st.size() << endl;
        return st.top();
    }
    string tree2string(TreeNode* root){
        if (root == nullptr) return "";
        string left = tree2string(root->left);
        string right = tree2string(root->right);
        if (left.size()) left = "(" + left + ")";
        if (right.size()) right = "(" + right + ")";
        return to_string(root->val) + left + right;
    }
};

int main() {
    Solution s1;
    //string s = "4(2(3)(1))(6)";
    vector<string> input = {"4(2(3)(1))(6(5))", "3(1(1)(2))"};
    for(auto s : input){
        auto ans = s1.str2tree(s);
        auto test = s1.tree2string(ans);
        cout << s << endl;
        cout << test << endl;
        assert(s == test);
    }
//    TreeNode *root1 = new TreeNode(2);
//    root1->left = new TreeNode(0);
//    root1->right = new TreeNode(4);
//    root1->right->right = new TreeNode(5);
//    auto ans = s1.boundaryOfBinaryTree(root1);

//    TreeNode *root2 = new TreeNode(1);
//    root2->right = new TreeNode(2);
//    TreeNode* r = root2->right;
//    r->left = new TreeNode(3);
//    r->right = new TreeNode(4);
//    auto ans = s1.boundaryOfBinaryTree(root2);

//    TreeNode *root3 = new TreeNode(1);
//    root3->left = new TreeNode(2);
//    root3->right = new TreeNode(3);
//    TreeNode* l = root3->left;
//    TreeNode* r = root3->right;
//    l->left = new TreeNode(4);
//    l->right = new TreeNode(5);
//    r->left = new TreeNode(6);
//    l->right->left = new TreeNode(7);
//    l->right->right = new TreeNode(8);
//    r->left->left = new TreeNode(9);
//    r->left->right = new TreeNode(10);
//    auto ans = s1.boundaryOfBinaryTree(root3);

   // showV(ans);
    //cout << ans << endl;
}
