#include "leetcode.h"

// 388. Longest Absolute File Path
class FileNode{
public:
    string val;
    vector<FileNode*> child;
    FileNode(string v) : val(v){};
    void addChild(FileNode* c){
        child.push_back(c);
    }
    void show(int level = 0){
        cout << string(4*level, ' ') << val << endl;
        for(const auto& t : child){
            t->show(level + 1);
        }
    }
    bool isFile(){
        return val.find('.') != string::npos;
    }


};
class Solution {
public:
    int lengthLongestPath(string input) {
        FileNode *root = new FileNode("");
        ret = 0;
        idx = 0;
        while(idx < input.size()){
            //cout << idx << endl;
            root->addChild(buildTree(input, 0));
            idx++;
        }
        //root->show();
        dfs(root, 0);
        return max(0, ret - 1);
    }
private:
    int idx;
    int ret;
    // "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    FileNode* buildTree(const string& input, int level){
        //cout << '[' << input.substr(idx) << "]  level:" << level << endl;
        if (input.size() == 0) return nullptr;
        int j = idx; // find node value;
        while(j < input.size() && input[j] != '\n') j++;
        FileNode *root = new FileNode(input.substr(idx, j - idx));
        idx = j + 1; // idx = '\t'

        for(; idx < input.size(); idx++){
            int tab = 0;
            while(input[idx + tab] == '\t'){
                tab++;
            }
            //cout << "idx: " << idx << " level:" << level << " tab:" << tab << endl;
            if (level + 1 == tab){
                idx += tab;
                root->addChild(buildTree(input, tab));
            } else {
                idx--;
                return root;
            }
        }
        return root;
    }
    void dfs(FileNode* root, int len){
        if (root->child.size() == 0 && root->isFile()){
            len += root->val.size();
            ret = max(ret, len);
        }
        for(const auto& c : root->child){
            dfs(c, len + root->val.size() + 1);
        }
    }
};


int main() {
    Solution s1;
    string input = "dir\n    file.txt";
    auto ans = s1.lengthLongestPath(input);
    cout << ans << endl;
}
