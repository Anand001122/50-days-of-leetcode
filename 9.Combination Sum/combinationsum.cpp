#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to perform backtracking and find all combinations
    void backtrack(vector<int>& candidates, int target, vector<int>& current,
                   vector<vector<int>>& result, int index) {
        // If target is zero, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Iterate over the candidates starting from the current index
        for (int i = index; i < candidates.size(); i++) {
            // If the current candidate can be used (i.e., less than or equal to target)
            if (candidates[i] <= target) {
                current.push_back(candidates[i]);  // Choose the candidate
                // Recurse with the updated target and same index for multiple occurrences of the same candidate
                backtrack(candidates, target - candidates[i], current, result, i);
                current.pop_back();  // Backtrack and remove the last candidate from the current combination
            }
        }
    }

    // Main function that returns all unique combinations of candidates that sum to target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;  // To store the valid combinations
        vector<int> current;  // To store the current combination being processed
        backtrack(candidates, target, current, result, 0);  // Start the backtracking process
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates;
    int target;

    // Take input from the user
    int temp;
    while (cin >> temp) {
        candidates.push_back(temp);
        if (cin.peek() == '\n') break;  // Stop when a newline is encountered
    }

    cin >> target;

    // Get all combinations
    vector<vector<int>> result = solution.combinationSum(candidates, target);  

    // Output the result
    if (result.empty()) {
        cout << "[]" << endl;  // Explicitly output [] for empty result
    } else {
        for (auto& combination : result) {
            cout << "[";
            for (int i = 0; i < combination.size(); i++) {
                cout << combination[i];
                if (i != combination.size() - 1) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}