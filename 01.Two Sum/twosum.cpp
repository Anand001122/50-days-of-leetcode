#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

int main() {
    int n, target;
    
    // Get array size
    cout << "Enter the size of the array: ";
    cin >> n;
    
    // Get array elements
    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Get target value
    cout << "Enter the target sum: ";
    cin >> target;
    
    // Find the solution
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    
    // Output the result
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}