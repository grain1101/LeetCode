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


class MinStack {
public:
    // 155. Min Stack
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x){
        st.push(x);
        if (minSt.empty() || x <= minSt.top()){
            minSt.push(x);
        }
    }

    void pop() {
        if(st.empty()) return;
        if (st.top() == minSt.top()){
            minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
private:
    stack<int> st;
    stack<int> minSt;
};

int main() {
//    Solution s1;
    Minstack obj = new Minstack();
    //show(result);
}
