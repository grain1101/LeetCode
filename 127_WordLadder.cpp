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
    // 127. Word Ladder
    // wordList = ["hot","dot","dog","lot","log","cog"]
    bool isAdjacent(const string& a, const string& b){
        int n = 0;
        for(int i = 0; i < a.size(); i++){
            if (a[i] != b[i]) n++;
        }
        return n == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> graph(n);
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i != j && isAdjacent(wordList[i], wordList[j])){
                    graph[i].push_back(j);
                }
            }
        }
        queue<int> q;
        vector<int> length(n, -1);
        for(int i = 0; i < n; i++){
            if (beginWord == wordList[i]){
                length[i] = 1;
                q.push(i);
            }
        }
        if (q.size() == 0){
            for(int i = 0; i < n; i++){
                if (isAdjacent(beginWord, wordList[i])){
                    length[i] = 2;
                    q.push(i);
                }
            }
        }
        while(q.size()){
            int i = q.front();
            q.pop();
            //cout << wordList[i] << " " << length[i] << endl;
            for(int j = graph[i].size() - 1; j >= 0; j--){
                int index = graph[i][j];
                if (length[index] != -1) continue;
                if (endWord == wordList[index]) return length[i] + 1;
                q.push(index);
                length[index] = length[i] + 1;
            }
        }
        return 0;
    }
};


int main() {
    Solution s1;
    vector<string> ss = {"hot","dot","dog","lot","log","cog"};
    auto result = s1.ladderLength("hit","cog",ss);
    cout << result << endl;
}
