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
    // 134. Gas Station
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int total = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
            if (sum < 0){
                total += sum;
                sum = 0;
                ans = i + 1;
            }
        }
        total += sum;
        return total >= 0 ? ans : -1;
    }
};

int main() {
    Solution s1;
    vector<int> gas = {3,5,7,1,2};
    vector<int> cost = {4,2,1,5,3};
    auto r = s1.canCompleteCircuit(gas, cost);
    cout << r << endl;
}
