class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int tmp = n;
            double sum = 0.0;
            while(tmp--){
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            //cout << sum << " " << tmp << endl;
            ret.push_back(sum * 1.0 / n);
        }
        return ret;
    }
};