#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool dp(int i, int j, const string& s, const string& p, unordered_map<string, bool>& memo) {
    if (memo.count(to_string(i) + "," + to_string(j))) {
        return memo[to_string(i) + "," + to_string(j)];
    }

    bool result;

    if (j == p.length()) {
        result = i == s.length();
    } else {
        bool firstMatch = i < s.length() && (p[j] == s[i] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*') {
            result = dp(i, j + 2, s, p, memo) || (firstMatch && dp(i + 1, j, s, p, memo));
        } else {
            result = firstMatch && dp(i + 1, j + 1, s, p, memo);
        }
    }

    memo[to_string(i) + "," + to_string(j)] = result;
    return result;
}

bool isMatch(const string& s, const string& p) {
    unordered_map<string, bool> memo;
    return dp(0, 0, s, p, memo);
}

int main() {
    string s, p;
    cin >> s >> p;

    bool isMatched = isMatch(s, p);
    cout << boolalpha << isMatched << endl;

    return 0;
}
