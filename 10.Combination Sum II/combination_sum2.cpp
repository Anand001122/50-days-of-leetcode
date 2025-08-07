#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }

private:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
};

int main() {
    vector<int> candidates;
    string line;
    
    // Read space-separated integers
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        candidates.push_back(num);
    }

    int target;
    cin >> target;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    for (const auto& comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}