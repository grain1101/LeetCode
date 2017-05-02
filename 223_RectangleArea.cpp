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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 223. Rectangle Area
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(left, min(C,G));
        int bottom = max(B,F), top = max(bottom, min(D,H));
        return (C-A)*(D-B) + (G-E)*(H-F)-(right-left)*(top-bottom);
    }
};

int main() {
    Solution s1;
    TreeNode* root = new TreeNode(1);
    auto ans = s1.countNodes(root);
    cout << (1<<1) << endl;
    //cout << ans << endl;
    //show(ans);
    //showV(ans);
}
