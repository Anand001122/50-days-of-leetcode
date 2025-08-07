#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[mid], arr[low]);
                mid++;
                low++;
            } else if (arr[mid] == 1) {
                mid++;
            } else if (arr[mid] == 2) {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

vector<int> parseInput(string input) {
    vector<int> nums;
    // Remove brackets
    input = input.substr(1, input.size() - 2);
    
    stringstream ss(input);
    string item;
    
    // Parse each number separated by commas
    while (getline(ss, item, ',')) {
        nums.push_back(stoi(item));
    }
    
    return nums;
}

void printArray(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    string input;
    getline(cin, input);
    
    vector<int> nums = parseInput(input);
    
    Solution solution;
    solution.sortColors(nums);
    
    printArray(nums);
    
    return 0;
}