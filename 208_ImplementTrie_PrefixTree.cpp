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
        a.assign(Sigma, nullptr);
        n = 0;
    }
};

class Trie {
public:
    // 208. Implement Trie (Prefix Tree)
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if (p->a[word[i]-'a'] == nullptr){
                p->a[word[i]-'a'] = new TrieNode();
            }
            p = p->a[word[i]-'a'];
        }
        p->n++;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = findWord(word);
        return p && (p->n) > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        return findWord(prefix) != nullptr;
    }

private:
    TrieNode *findWord(string word){
        TrieNode *p = root;
        for(int i = 0; i < word.size(); i++){
            if (p ==  nullptr) return nullptr;
            p = p->a[word[i]-'a'];
        }
        return p;
    }
};



int main() {
    //Solution s1;
    string word = "abc";
    string ww = "a";
    Trie *trie = new Trie();
    trie->insert(word);
    auto ans = trie->search(word);
    cout << ans << endl;
}
