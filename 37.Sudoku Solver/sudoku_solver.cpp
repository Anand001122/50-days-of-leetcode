#include <bits/stdc++.h>
using namespace std;

// Check if placing num at (row, col) is valid
bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    // Check 3x3 sub-box
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for (int r = sr; r < sr + 3; r++) {
        for (int c = sc; c < sc + 3; c++) {
            if (board[r][c] == num)
                return false;
        }
    }
    return true;
}

// Backtracking solver
bool solveSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(board, r, c, num)) {
                        board[r][c] = num;
                        if (solveSudoku(board))
                            return true;
                        board[r][c] = '.';  // backtrack
                    }
                }
                return false;  // trigger backtrack
            }
        }
    }
    return true;  // solved
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board(9, vector<char>(9));
    // Read 9 lines, each with 9 space-separated characters (digit or '.')
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    // Solve the puzzle
    solveSudoku(board);

    // Print the solved board
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
            if (j < 8) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}