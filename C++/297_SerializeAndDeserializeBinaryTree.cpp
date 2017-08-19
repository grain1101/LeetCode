#include "leetcode.h"

class Codec {
public:
    // 297. Serialize and Deserialize Binary Tree
    // In_order traversal
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "[";
        bfs(root, ret);
        ret.resize(ret.size() - 1);
        ret += "]";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto nums = stringSplit(data.substr(1, data.size() - 2));

        //showV(nums);
        if (nums.size() == 1 && nums[0] == "null") return nullptr;
        int i = 0;
        TreeNode* root = new TreeNode(stoi(nums[i++]));
        queue<TreeNode*> q;
        q.push(root);
        while(i < nums.size() || !q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if (nums[i] != "null") tmp->left = new TreeNode(stoi(nums[i]));
            if (nums[i+1] != "null") tmp->right = new TreeNode(stoi(nums[i + 1]));
            i += 2;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return root;
    }
private:
    vector<string> stringSplit(string& s){
        vector<string> ret;
        int j = 0;
        for(int i = 1; i <= s.size(); i++){
            if (i == s.size() || s[i] == ','){
                string tmp = s.substr(j, i - j);
                ret.push_back(tmp);
                j = i+1;
            }
        }
        return ret;
    }
    void inorder(TreeNode* root, string& ret){
        if (root == nullptr){
            ret += "null";
            return;
        }
        inorder(root->left, ret);
        ret += "," + to_string(root->val) + ",";
        inorder(root->right, ret);
    }
    void bfs(TreeNode* root, string& ret){
        queue<TreeNode*> q;
        if (root == nullptr){
            ret += "null,";
            return;
        }
        q.push(root);
        q.push(root->left);
        q.push(root->right);
        ret += to_string(root->val) + ",";
        q.pop();
        while(!q.empty()){
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == nullptr) ret += "null,";
            else {
                ret += to_string(tmp->val) + ",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
    }
};

int main() {
    Codec c;
    string s = "[1,2,null,null,null]";
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    //auto serialize = c.serialize(root);
    auto ans = c.deserialize(s);
    auto serialize = c.serialize(ans);
    cout << serialize << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
