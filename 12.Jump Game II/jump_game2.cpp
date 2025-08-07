#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    string line;
    
    // Read input as space-separated integers
    getline(cin, line);
    stringstream ss(line);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }

    // Output the minimum number of jumps to reach the last index
    cout << sol.jump(nums) << endl;

    return 0;
}