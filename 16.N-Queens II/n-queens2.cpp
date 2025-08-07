#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;

    void solve(int col, int n,
               unordered_map<int, int> &rowMap,
               unordered_map<int, int> &leftUpMap,
               unordered_map<int, int> &leftDownMap) {

        if (col == n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rowMap[row] == 0 &&
                leftDownMap[row + col] == 0 &&
                leftUpMap[n - 1 + col - row] == 0) {

                rowMap[row]++;
                leftDownMap[row + col]++;
                leftUpMap[n - 1 + col - row]++;

                solve(col + 1, n, rowMap, leftUpMap, leftDownMap);

                rowMap[row]--;
                leftDownMap[row + col]--;
                leftUpMap[n - 1 + col - row]--;
            }
        }
    }

    int totalNQueens(int n) {
        unordered_map<int, int> rowMap, leftUpMap, leftDownMap;
        solve(0, n, rowMap, leftUpMap, leftDownMap);
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    Solution sol;
    cout << sol.totalNQueens(n);
    return 0;
}
