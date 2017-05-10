#include "leetcode.h"

class Solution {
public:
    // 289. Game of Life
    // 1->live; 0->dead;
    // xy; x->child status; y->current status;
    // 00; dead <- dead;
    // 01; dead <- live;
    // 10; live <- dead;
    // 11; live <- live;
    // board[i][j] & 1 -> to see "y" bit is 1 or 0;
    int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int live = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
                    if (board[x][y] & 1) live++;
                }
                if (board[i][j] == 0){
                    if (live == 3){
                        board[i][j] = 2; // 10; live <- dead;
                    }
                } else {
                    if (live < 2 || live > 3){
                        board[i][j] = 1;
                    }
                    else {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] >>= 1;
            }
        }
    }
};

int main() {
    Solution s1;
    vector<int> nums = {2,3,1,4,3};
    auto ans = s1.gameOfLife()
    cout << ans << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
