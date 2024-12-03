// Question Link - https://leetcode.com/problems/n-queens-ii/description/

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 9

#include<bits/stdc++.h>
using namespace std;

bool checker(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
        else if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q')
            return false;
        else if (col + (row - i) < n && board[i][col + (row - i)] == 'Q')
            return false;
    }
    return true;
}

void helper(int n, vector<vector<string>>& res, vector<string>& board, int row) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (checker(board, row, col, n)) {
            board[row][col] = 'Q';
            helper(n, res, board, row + 1);
            board[row][col] = '.';
        }
    }
}

int totalNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    helper(n, res, board, 0);
    return res.size();
}

int main() {
    int n;
    cin >> n;

    cout << totalNQueens(n) << endl;

    return 0;
}
