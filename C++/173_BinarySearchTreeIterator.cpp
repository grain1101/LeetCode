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
        cout << r << " ";
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class BSTIterator {
public:
    // 173. Binary Search Tree Iterator
	BSTIterator(TreeNode *root){
		findLeft(root);
	}
	bool hasNext(){
		return st.size() != 0;
	}
	int next(){
		TreeNode *top = st.top();
		st.pop();
		findLeft(top->right);
		return top->val;
	}
	void findLeft(TreeNode *root){
		while(root){
			st.push(root);
			root = root->left;
		}
	}
private:
	stack<TreeNode*>  st;
};

int main() {
}
