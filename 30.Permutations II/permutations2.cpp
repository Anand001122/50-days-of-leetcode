#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        do {
            v.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return v;
    }
};

int main() {
    Solution solution;
    
    // Taking input from user as space-separated values
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> nums;
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    vector<vector<int>> result = solution.permuteUnique(nums);

    // Printing the result in the desired format
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}