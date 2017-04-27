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
#include<list>
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
        cout << r << endl;
    cout << endl;
}

class Trie{
public:
    vector<Trie*> children;
    bool Leaf;
    int wordIdx;
    int prefixCount;
    Trie(){
        children.assign(26, nullptr);
        Leaf = false;
        wordIdx = 0;
        prefixCount = 0;
    }
    ~Trie(){
        for(auto c : children) delete c;
    }
};

class Solution {
private:
    const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // adjacent cell;
    vector<vector<char>> _board;
    vector<string> _words;
    vector<string> ans;

    void insertWord(Trie* root, const vector<string>& words, int idx){
        for(int i = 0; i < words[idx].size(); i++){
            int c = words[idx][i] - 'a';
            if (root->children[c] == nullptr) root->children[c] = new Trie();
            root = root->children[c];
        }
        root->Leaf = true;
        root->wordIdx = idx;
    }

    Trie *buildTrie(const vector<string> &words){
        Trie *root = new Trie();
        for(int i = 0; i < words.size(); i++){
            insertWord(root, words, i);
        }
        return root;
    }

    void checkWords(Trie *root, int i, int j){
        if (root == nullptr || !checkAccessible(i, j)) return;
        char temp = _board[i][j];
        Trie *p = root->children[temp-'a'];
        if (p == nullptr) return;
        if (p->Leaf){
            ans.push_back(_words[p->wordIdx]);
            p->Leaf = false;
        }
        _board[i][j] = '*';
        for(int k = 0; k < 4; k++){
            checkWords(p, i + d[k][0], j + d[k][1]);
        }
        _board[i][j] = temp;
    }

    bool checkAccessible(int x, int y){
         // if out of boundary or already visited, return false;
        if (x >=0 && x < _board.size() && y >= 0 && y < _board[0].size() && _board[x][y] != '*') return true;
        return false;
    }

public:
    // 212. Word Search II
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        _board = board;
        _words = words;
        Trie *root = buildTrie(words);
        for(int i = 0; i < _board.size(); i++){
            for(int j = 0; j < _board[i].size(); j++){
                checkWords(root, i, j);
            }
        }
        return ans;
    }
};



int main() {
   Solution s1;
   vector<string> ss = {"oaan","etae","ihkr","iflv"};
   vector<vector<char>> board(ss.size());
   for(int i = 0; i < ss.size(); i++){
        for(int j = 0; j < ss[i].size(); j++){
            board[i].push_back(ss[i][j]);
        }
   }
   showV(ss);
   vector<string> words = {"oath","pea","eat","rain"};
   auto ans = s1.findWords(board, words);
   showV(ans);
}
