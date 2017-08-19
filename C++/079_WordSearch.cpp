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

class Solution {
  public:
    // 79. Word Search
    // DFS
    // The same letter cell may not be used more than once.
    int d[4][2] = {{-1,0}, {0,1}, {1,0},{0,-1}};
    //vector<vector<char>>& board;

    bool checkRange(int x, int y, const vector<vector<char>>& board){
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        return true;
    }
    bool dfs(const vector<vector<char>>& board, const string& word, vector<vector<char>>& mark, int sx, int sy, int level){
        if (level == word.size() - 1) {
            return true;
        }
        mark[sx][sy] = '1';
        for(int i = 0; i < 4; i++){
            int tx = sx + d[i][0];
            int ty = sy + d[i][1];
            if (checkRange(tx, ty, board) && board[tx][ty] == word[level+1] && mark[tx][ty] == '0') {
                //cout << word[level] << " " << tx << " " << ty << " " << level << endl;
                if (dfs(board, word, mark, tx, ty, level + 1)) return true;
            }
        }
        mark[sx][sy] = '0';
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0 || board.size() == 0 || board[0].size() == 0) return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    vector<vector<char>> mark(board.size(), vector<char>(board[0].size(), '0'));
                    if (dfs(board, word, mark, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3};
//    vector<vector<string>> board1 = {{"ABCE"}, {"SFCS"}, {"ADEE"}};
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
//    for(auto s : board1){
//        int i = 0;
//        for(auto c : s){
//            board[i].push_back(c);
//        }
//        i++;
//    }
    string word = "ABCCED";
    Solution s1;
    auto result = s1.exist(board, word);
    //show(result);
    cout << result << endl;
    return 0;
}
