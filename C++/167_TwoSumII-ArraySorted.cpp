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

class Solution {
public:
    // 167. Two Sum II - Input array is sorted
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) return {};
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if (numbers[l] + numbers[r] == target) return {l + 1, r + 1};
            if (numbers[l] + numbers[r] > target) r--;
            if (numbers[l] + numbers[r] < target) l++;
        }
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto r = s1.twoSum(nums, target);
    showV(r);
}
