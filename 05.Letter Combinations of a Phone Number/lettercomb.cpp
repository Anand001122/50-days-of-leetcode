#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    // Mapping of digits to letters as per the phone number keypad
    const string phoneMap[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    // Helper function to perform backtracking
    void backtrack(const string &digits, int index, string &current, vector<string> &result) {
        // If we have processed all digits, add the current combination to the result
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the corresponding letters for the current digit
        int digit = digits[index] - '0';
        string letters = phoneMap[digit];

        // Recurse for each letter corresponding to the current digit
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();  // Backtrack to explore the next letter
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;  // Return empty list if input is empty
        }

        string current;
        backtrack(digits, 0, current, result);  // Start backtracking from index 0
        return result;
    }
};

int main() {
    string digits;
    cin >> digits;  // Accept input from the user
    
    Solution sol;
    vector<string> combinations = sol.letterCombinations(digits);

    // Print the result in the desired format
    cout << "[";
    for (int i = 0; i < combinations.size(); i++) {
        cout << "'" << combinations[i] << "'";
        if (i < combinations.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}