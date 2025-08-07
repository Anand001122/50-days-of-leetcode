#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, temp, used, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used, vector<vector<int>>& res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, used, res);
            temp.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    // Input format: space-separated integers (e.g., 1 2 3)
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') break;
    }

    Solution solution;
    vector<vector<int>> result = solution.permute(nums);

    for (const auto& perm : result) {
        cout << "[";
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i];
            if (i != perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}