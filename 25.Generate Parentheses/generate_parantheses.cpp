#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Backtracking helper to build valid parentheses strings
void backtrack(int n, int openCount, int closeCount, string &current, vector<string> &result) {
    if ((int)current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    // Add '(' if we still can
    if (openCount < n) {
        current.push_back('(');
        backtrack(n, openCount + 1, closeCount, current, result);
        current.pop_back();
    }
    // Add ')' if it remains valid
    if (closeCount < openCount) {
        current.push_back(')');
        backtrack(n, openCount, closeCount + 1, current, result);
        current.pop_back();
    }
}

// Generates all well‑formed parentheses combinations for n pairs
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    current.reserve(2 * n);
    backtrack(n, 0, 0, current, result);
    return result;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> ans = generateParenthesis(n);

    // Print in JSON-like array format: ["((()))","(()())",...]
    cout << "[";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << "\"" << ans[i] << "\"";
        if (i + 1 < ans.size()) cout << ",";
    }
    cout << "]\n";
    return 0;
}
