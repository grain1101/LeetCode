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
    // 174. Dungeon Game
    int calculateMinimumHP(vector<vector<int>>& dumgeon){
        int n = dumgeon.size();
        int m = dumgeon[0].size();
        vector<vector<int>> hp(n + 1, vector<int>(m + 1, INT_MAX));
        hp[n][m - 1] = hp[n - 1][m] = 1;
        for(int i = n - 1; i >=0; i--){
            for(int j = m - 1; j >= 0; j--){
                int tmp = min(hp[i][j + 1], hp[i + 1][j]) - dumgeon[i][j];
                hp[i][j] = tmp > 0 ? tmp : 1;
            }
        }
        return hp[0][0];
    }
};

int main() {
}
