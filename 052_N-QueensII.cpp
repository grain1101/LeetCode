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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    // 52. N-Queens II
    //
    bool checkRange(vector<string>& board, int i, int j){
        int n = board.size();
        if(i < 0 || i >= n || j < 0 || j >= n ) return true;
        return board[i][j] == '.';
    }
    bool checkQ(vector<string>& board, int i, int j){
        static int x[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
        static int y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
        if(!checkRange(board, i, j)) return false;
        for(int step = 0; step < board.size(); step++){
            for(int p = 0; p < 8; p++){
                if(!checkRange(board, i + x[p]*step, j + y[p]*step)){
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(vector<vector<string>>& ans, vector<string>& board, int queens){
        if (queens == board.size()){
            ans.push_back(board);
            return;
        }
        //show(board);
        for(int j = 0; j < board.size(); j++){
            if(checkQ(board, queens, j)) {
                board[queens][j] = 'Q';
                dfs(ans, board, queens + 1);
                board[queens][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        dfs(ans, board, 0);
        return ans.size();
    }
};


int main() {
    vector<int> nums = {3,3,0,0,2,3,2};
    Solution s1;
    auto result = s1.totalNQueens(8);
//    for(auto r : result){
//        for(auto t : r){
//            cout << t<<endl;
//        }
//        cout << endl;
//    }
    cout << result << endl;
    return 0;
}
