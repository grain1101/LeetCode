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
        cout << r << " ";
    cout << endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

const int Sigma = 26;
class TrieNode{
public:
    vector<TrieNode*> a;
    int n;
    TrieNode(){
        a.assign(Sigma, 0);
        n = 0;
    }
};

class WordDictionary {
public:
    // 211. Add and Search Word - Data structure design
    /** Initialize your data structure here. */
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if (p->a[word[i]-'a'] == nullptr) {
                p->a[word[i]-'a'] = new TrieNode();
            }
            p = p->a[word[i]-'a'];
        }
        p->n++;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(const string &word, int index, TrieNode *root){
        if (root == nullptr) return false;
        if (index == word.size()) return root->n > 0;
        if (word[index] != '.') return dfs(word, index + 1, root->a[word[index]-'a']);
        for(int i = 0; i < Sigma; i++){
            if (dfs(word, index + 1, root->a[i])) return true;
        }
        return false;
    }
};



int main() {
    WordDictionary *wd = new WordDictionary();
    string word = "dad";
    string word1 = ".d.";
    wd->addWord(word);
    auto ans = wd->search(word1);
    cout << ans << endl;
}
