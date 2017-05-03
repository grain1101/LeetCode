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

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> que;

    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size() - 1; i++){
        	que.push(que.front());
        	que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = que.front();
        que.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};


int main() {
    MyStack s1;
    s1.push(1);
    s1.push(2);
    cout << s1.pop() << endl;
    cout << s1.top() << endl;
    cout << s1.empty() << endl;
    //cout << ans << endl;
    //show(ans);
    //showV(ans);
}
