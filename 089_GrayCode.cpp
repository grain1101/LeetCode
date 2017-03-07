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
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t;
        }
        cout << endl;
    }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 89. Gray Code
    // two component
    // 2^n = 1<<n
    // i&-i = the first 1 of i from right side
    vector<int> grayCode(int n) {
        vector<int> gray(1<<n, 0);
        for(int i = 1; i < (1<<n); i++){
            gray[i] = (gray[i - 1] ^ (i & -i));
        }
        return gray;
    }
};


int main() {

}
