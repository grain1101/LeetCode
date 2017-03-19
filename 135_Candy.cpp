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
    // 135. Candy
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 2) return n;
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++){
            if (ratings[i] <= ratings[i - 1]) continue;
            //else if (ratings[i] == ratings[i - 1]) candies[i] = candies[i - 1];
            else candies[i] = candies[i - 1] + 1;
        }
        //showV(candies);
        for(int i = n - 2; i >= 0; i--){
            if (ratings[i] <= ratings[i + 1]) continue;
            //else if (ratings[i] == ratings[i + 1]) candies[i] = candies[i + 1];
            else candies[i] = max(candies[i], candies[i + 1] + 1);
        }
        //showV(candies);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += candies[i];
        }
        return ans;
    }
};

int main() {
    Solution s1;
    vector<int> ratings = {1,2,2};
    auto r = s1.candy(ratings);
    cout << r << endl;
}
