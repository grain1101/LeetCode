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
public:
    // 126. Word Ladder II
    // wordList = ["hot","dot","dog","lot","log","cog"]
    bool isAdjacent(string a, string b){
        int n = 0;
        for(int i = 0; i < a.size(); i++){
            if (a[i] != b[i]) n++;
        }
        return n == 1;
    }
    void dfs(vector<int>& path, int root, const vector<string>& wordList){
        if (root == -1){
            vector<string> tmp = {_beginword};
            for(int i = path.size() - 1; i >= 0; i--){
                tmp.push_back(wordList[path[i]]);
            }
            ans.push_back(tmp);
            return;
        }
        path.push_back(root);
        for(auto r : preNode[root]){
            dfs(path, r, wordList);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // build graph
        int n = wordList.size();
        _beginword = beginWord;
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i != j && isAdjacent(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                }
            }
        }
        // find first transformation
        queue<int> q;
        vector<int> length(n, -1);
        preNode.assign(n, vector<int>());
        ans.clear();
        for(int i = 0; i < n; i++){
            if (isAdjacent(beginWord, wordList[i])){
                q.push(i);
                preNode[i].push_back(-1);
                length[i] = 1;
            }
        }
        // add PreNode to generate all possible paths.
        int endIndex = -1;
        while(q.size()){
            int cur = q.front();
            q.pop();
            if (endWord == wordList[cur]) {
                endIndex = cur;
                break;
            }
            for(int i = 0; i < graph[cur].size(); i++){
                int index = graph[cur][i];
                if (length[cur] + 1 == length[index]){
                    preNode[index].push_back(cur);
                }
                if (length[index] == -1) {
                    preNode[index].push_back(cur);
                    length[index] = length[cur] + 1;
                    q.push(index);
                }
            }
        }
        if (endIndex == -1) return ans;
        // generate PreNode graph's paths
        vector<int> path;
        dfs(path, endIndex, wordList);
        return ans;
    }
private:
    vector<vector<int>> preNode;
    vector<vector<string>> ans;
    string _beginword;
};


int main() {
    Solution s1;
    vector<string> ss = {"hot","dot","dog","lot","log","cog"};
    auto result = s1.findLadders("hit","cog",ss);
    show(result);
}
