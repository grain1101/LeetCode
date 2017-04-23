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

class Solution {
public:
    // 200. Number of Islands
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        _grid = grid;
        n = _grid.size();
        m = _grid[0].size();
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (_grid[i][j] == '1'){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int i, int j){
        if (outRange(i, j) || _grid[i][j] != '1') return;
        _grid[i][j] = 'x';
        for(int k = 0; k < 4; k++){
            dfs(i + x[k], j + y[k]);
        }
        return;
    }
    bool outRange(int i, int j){
        if (i < 0 || i >= n || j < 0 || j >= m) return true;
        return false;
    }
private:
    vector<vector<char>> _grid;
    int n;
    int m;
    int ans;
    const vector<int> x = {-1,1,0,0};
    const vector<int> y = {0,0,-1,1};
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    vector<string> tmp = {"11110","11010","11000","00000"};
    vector<vector<char>> grid(tmp.size());
    for(int i = 0; i < tmp.size(); i++){
        for(int j = 0; j < tmp[i].size();j++){
            grid[i].push_back(tmp[i][j]);
        }
    }
    //show(grid);
    auto ans = s1.numIslands(grid);
    cout << ans << endl;
}
