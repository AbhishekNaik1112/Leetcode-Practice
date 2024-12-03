// Question Link - https://leetcode.com/problems/n-queens/description/

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9

#include<bits/stdc++.h>
using namespace std;

bool checker(int n, vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
        else if (col + (row - i) < n && board[i][col + (row - i)] == 'Q')
            return false;
        else if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q')
            return false;
    }
    return true;
}

void helper(int n, vector<vector<string>>& res, vector<string>& board, int row) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < board.size(); col++) {
        if (checker(n, board, row, col)) {
            board[row][col] = 'Q';
            helper(n, res, board, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    helper(n, res, board, 0);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> sols = solveNQueens(n);

    for (const auto& sol : sols) {
        for (const string& i : sol) {
            cout << i << endl;
        }
        cout << endl;
    }

    return 0;
}
