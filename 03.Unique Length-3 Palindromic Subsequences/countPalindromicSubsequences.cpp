#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, vector<int>> mp;
        for (size_t i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        set<string> result;
        for (auto it : mp) {
            vector<int> ind = it.second;
            int st = ind[0];
            int e = ind[ind.size() - 1];
            if (e - st <= 1) continue;

            set<char> midChars;
            for (int i = st + 1; i < e; i++) {
                midChars.insert(s[i]);
            }

            for (char mid : midChars) {
                string pal = "";
                pal += it.first;
                pal += mid;
                pal += it.first;
                result.insert(pal);
            }
        }

        return result.size();
    }
};

int main() {
    int n;
    string s;
    cin >> n >> s;

    Solution sol;
    int res = sol.countPalindromicSubsequence(s);
    cout << res << endl;

    return 0;
}
