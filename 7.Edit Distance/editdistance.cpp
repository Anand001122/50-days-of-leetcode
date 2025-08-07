#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minRec(word1, m - 1, word2, n - 1, dp);
    }

    int minRec(string &w1, int i1, string &w2, int i2, vector<vector<int>> &dp) {
        if (i2 < 0) return i1 + 1;
        if (i1 < 0) return i2 + 1;
        if (dp[i1][i2] != -1) return dp[i1][i2];

        if (w1[i1] == w2[i2]) {
            dp[i1][i2] = minRec(w1, i1 - 1, w2, i2 - 1, dp);
        } else {
            int replace = minRec(w1, i1 - 1, w2, i2 - 1, dp);
            int deleteOp = minRec(w1, i1 - 1, w2, i2, dp);
            int insert = minRec(w1, i1, w2, i2 - 1, dp);
            dp[i1][i2] = min({replace, deleteOp, insert}) + 1;
        }
        return dp[i1][i2];
    }
};

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    Solution sol;
    cout << sol.minDistance(word1, word2);
    return 0;
}
