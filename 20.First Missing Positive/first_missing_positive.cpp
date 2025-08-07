#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Mark numbers that are out of the range [1, n] as n+1 (an invalid number)
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Use index to mark presence of numbers
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]); // Mark as negative to indicate the presence of the number
            }
        }

        // Step 3: Find the first index with a positive number, that means the index + 1 is the missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If no missing number, return n + 1
        return n + 1;
    }
};

int main() {
    Solution solution;

    // Get input from the user
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = solution.firstMissingPositive(nums);
    cout << result ;

    return 0;
}
