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

class MyStack {
public:
    // 225. Implement Stack using Queues
    /** Initialize your data structure here. */
    MyStack(): q(vector<queue<int>>(2)), activeIdx(0) {
    }

    /** Push element x onto stack. */
    void push(int x) {
        pushQueue(x, activeIdx);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        emptyQueue();
        int ret = q[activeIdx].front();
        q[activeIdx].pop();
        activeIdx ^= 1;
        return ret;
    }

    /** Get the top element. */
    int top() {
        emptyQueue();
        int ret = q[activeIdx].front();
        q[activeIdx ^ 1].push(q[activeIdx].front());
        q[activeIdx].pop();
        activeIdx ^= 1;
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q[activeIdx].empty();
    }
private:
    int activeIdx;
    vector<queue<int>> q;
    void emptyQueue(){
        while(q[activeIdx].size() > 1){
            q[activeIdx ^ 1].push(q[activeIdx].front());
            q[activeIdx].pop();
        }
    }
    void pushQueue(int x, int activeIdx){
        q[activeIdx].push(x);
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
