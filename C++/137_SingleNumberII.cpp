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
    // 137. Single Number II
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (nums[i] ^ ones) & ~twos & ~threes;
            twos = (nums[i] ^ twos) & ~ones & ~threes;
            threes = (nums[i] ^ threes) & ~ones & ~twos;
        }
        cout << ones << endl;
        cout << twos << endl;
        cout << threes << endl;
        return ones;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,1,1,1,2,2,2,2,3,3,3,3,4};
    auto r = s1.singleNumber(nums);
    cout << r << endl;
}
