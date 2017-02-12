#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 37. Sudoku Solver
    // DFS
    bool flag = false;
    bool isValid(vector<vector<char>>& board,
                 vector<vector<int>>&  row,
                 vector<vector<int>>&  col,
                 vector<vector<int>>&  cel,
                 int i, int j, int num){
            int k = i/3*3 + j/3;
            if (row[i][num] || col[j][num] || cel[k][num]) return false;
            else row[i][num] = col[j][num] = cel[k][num] = 1;
            return true;
    }
    void dfs(vector<vector<char>>& board,
             vector<vector<int>>&  row,
             vector<vector<int>>&  col,
             vector<vector<int>>&  cel, int i, int j){
        if (i==9 && j==0) {
            flag = true;
            return;
        }
        int k = i/3*3 + j/3;
        //cout << "i:" << i << " j:" << j << endl;
        //getchar();
        int ii = i + (j+1)/9;
        int jj = (j + 1)%9;
        if (board[i][j] == '.'){
            for(int t=0;t<9;t++){
                if (isValid(board, row, col, cel, i, j, t)) {
                        board[i][j] = t + 1 + '0';
                        dfs(board, row, col, cel, ii, jj);
                        if(flag){
                           return;
                        }
                        board[i][j] = '.';
                        row[i][t] = col[j][t] = cel[k][t] = 0;
                }
            }
        } else {
            dfs(board, row, col, cel, ii, jj);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> cel(9, vector<int>(9, 0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;
                    row[i][num] = col[j][num] = cel[k][num] = 1;
                }
            }
        }
        flag = false;
        dfs(board, row, col, cel, 0, 0);
        return;
    }
};

void show(vector<vector<char>> sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << sudoku[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // 1. Input test cases
    int num = 999;
    vector<int> nums = {1,3,5,6};
    string ss = "))))()";
    string ss2 = "ab*bbc";
    vector<string> strs = {"ab","abb","abc"};
    ListNode* head = new ListNode(0);
    ListNode *p = head;
    int n = 3;
    vector<ListNode*> lists;
    vector<vector<char>> sudoku1(9, vector<char>(9,'.'));
    vector<vector<char>> sudoku2(9, vector<char>(9,'.'));
    vector<string> input1 = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<string> input2 = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sudoku1[i][j] = input1[i][j];
            sudoku2[i][j] = input2[i][j];
        }
    }

    show(sudoku1);
    cout << "================" << endl;
    // 2. Run
    Solution s1;
    s1.solveSudoku(sudoku1);
    show(sudoku1);

    cout << "================" << endl;
    show(sudoku2);
    cout << "================" << endl;
    // 2. Run

    s1.solveSudoku(sudoku2);
    show(sudoku2);

    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
//    cout << result << endl;
    return 0;
}
