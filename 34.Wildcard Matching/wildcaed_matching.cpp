#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // DP table initialization
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Handle '*' in pattern when string is empty
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    // If the characters match or '?' matches any character
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can match empty sequence or any sequence
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n]; // Return the result at the bottom-right corner
    }
};

int main() {
    Solution solution;
    
    // Taking input from the user
    string s, p;
    cin >> s;
    cin >> p;

    bool result = solution.isMatch(s, p);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
