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
#include <set>
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

typedef pair<int, int> PII;
class Solution {
public:
    // 130. Surrounded Regions
    // 1. find all "O" on the board's edges. set them as "1"
    // 2. set other "O" in inner board as "X"
    // 3. set "1" as "O"
    bool check(int x, int y){
        return (x >= 0 && x < board.size() && y >=0 && y < board[0].size() && board[x][y] == 'O');
    }
    void dfs(int x, int y){
        stack<PII> st;
        st.push(PII(x, y));
        while(st.size()){
            PII cur = st.top();
            st.pop();
            if (!check(cur.first, cur.second)) continue;
            board[cur.first][cur.second] = '1';
            st.push(PII(cur.first - 1, cur.second));
            st.push(PII(cur.first + 1, cur.second));
            st.push(PII(cur.first, cur.second - 1));
            st.push(PII(cur.first, cur.second + 1));
        }

    }
    void solve(vector<vector<char>>& _board) {
        board = _board;
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;
        // 1. find all "O" on the board's edges. set them as "1"
        for(int i = 0; i < n; i++){
            dfs(i, 0);
            dfs(i, m - 1);
        }
        for(int j = 0; j < m; j++){
            dfs(0, j);
            dfs(n - 1, j);
        }
        // 2. set other "O" in inner board as "X"
        // 3. set "1" as "O"
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
        _board = board;
        return;
    }
private:
    vector<vector<char>> board;
};

int main() {
    Solution s1;
    vector<vector<char>> board;
    s1.solve(board);
}
