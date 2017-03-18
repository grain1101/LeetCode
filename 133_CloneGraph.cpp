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
#include <cassert>
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    // 133. Clone Graph
    void copyNode(UndirectedGraphNode *node){
        if (node == nullptr || labelMap.find(node->label) != labelMap.end()) return;
        labelMap[node->label] = new UndirectedGraphNode(node->label);
        for(auto n : node->neighbors){
            copyNode(n);
        }
    }
    void copyEdge(UndirectedGraphNode *node, set<int>& visited){
        if (node == nullptr || visited.find(node->label) != visited.end()) return;
        visited.insert(node->label);
        for(auto n : node->neighbors){
            // notice!! push neighbors is not n! it should be in labelMap.
            labelMap[node->label]->neighbors.push_back(labelMap[n->label]);
            copyEdge(n, visited);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return node;
        copyNode(node);
        set<int> visited;
        copyEdge(node, visited);
        return labelMap[node->label];
    }
private:
    unordered_map<int, UndirectedGraphNode*> labelMap;
};

int main() {
    Solution s1;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    auto r = s1.wordBreak(s, wordDict);
    for(auto tmp : r){
        cout << tmp << endl;
    }
}
