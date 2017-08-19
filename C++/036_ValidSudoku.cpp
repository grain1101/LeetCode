#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    // 36. Valid Sudoku
    // Only check the provided Sudoku is valid.
    // There is no need to find a valid Sudoku solution for this problem.
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size()==0 || board.size()!=9 || board[0].size()!=9) return false;
        vector<vector<int>> row(9, vector<int> (9,0));
        vector<vector<int>> col(9, vector<int> (9,0));
        vector<vector<int>> cell(9, vector<int> (9,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3; // calculate which board[i][j] in which cell
                    if(row[i][num] || col[j][num] || cell[k][num]) return false;
                    row[i][num] = 1;
                    col[j][num] = 1;
                    cell[k][num] = 1;
                }
            }
        }
        return true;
    }
};

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

    // 2. Run
    Solution s1;
    auto result = s1.searchInsert(nums, 0);
    // 3. Compare output
//    for(auto i : result){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << result << endl;
    return 0;
}
