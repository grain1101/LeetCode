#include "leetcode.h"

// 417. Pacific Atlantic Water Flow
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        ret.clear();
        if (matrix.size() == 0 || matrix[0].size() == 0) return ret;
        _matrix = matrix;
        n = _matrix.size(); m = _matrix[0].size();
        mark.assign(n, vector<int>(m, 0));
        for(int i = 0; i < _matrix.size(); i++) {
            dfs(i, 0, 1);
            dfs(i, m - 1, 2);
        }
        for(int j = 0; j < _matrix[0].size(); j++) {
            dfs(0, j, 1);
            dfs(n - 1, j, 2);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (mark[i][j] == 3) ret.push_back({i,j});
            }
        }
        return ret;
    }
private:
    vector<pair<int, int>> ret;
    vector<vector<int>> mark;
    vector<vector<int>> d = {{-1, 0}, {0, -1}, {1, 0},  {0, 1}};
    vector<vector<int>> _matrix;
    int n, m;
    bool checkBoundary(int x, int y){
        return x >= 0 && x < _matrix.size() && y >= 0 && y < _matrix[0].size();
    }
    void dfs(int x, int y, int c){
        //cout <<string(step * 2, ' ')<<"dfs:" << x << " " << y << endl;
        int &flag = mark[x][y];
        if ((flag >> (c - 1))&1) return;
        flag |= c;
        for(int i = 0; i < 4; i++){
            if (checkBoundary(x + d[i][0], y + d[i][1]) && _matrix[x][y] <= _matrix[x+d[i][0]][y+d[i][1]])
                {
                    dfs(x + d[i][0], y + d[i][1], c);
                }
        }
        //cout << string(step * 2, ' ') << x << " " << y << ", flag = " << flag << endl;
    }
};

int main() {
    Solution s1;
    vector<int> nums = {1,2,3,5,7,14,21};
    vector<vector<int>> matrix = {{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}};
    auto ans = s1.pacificAtlantic(matrix);
    for(auto n : ans){
        cout << n.first << " " << n.second << endl;
    }
    //cout << ans << endl;
}
