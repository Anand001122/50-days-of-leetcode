#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class NQueens {
    vector<vector<string>> solutions;

public:
    void solve(int col, int n, vector<string>& board, unordered_set<int>& rows, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rows.count(row) || diag1.count(col - row) || diag2.count(col + row)) continue;

            board[row][col] = 'Q';
            rows.insert(row);
            diag1.insert(col - row);
            diag2.insert(col + row);

            solve(col + 1, n, board, rows, diag1, diag2);

            board[row][col] = '.';
            rows.erase(row);
            diag1.erase(col - row);
            diag2.erase(col + row);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        unordered_set<int> rows, diag1, diag2;
        solve(0, n, board, rows, diag1, diag2);
        return solutions;
    }
};

int main() {
    int n;
    cin >> n;
    NQueens obj;
    vector<vector<string>> result = obj.solveNQueens(n);

    cout << result.size() << endl;

    for (auto& solution : result) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
