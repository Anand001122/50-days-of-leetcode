#include <iostream>
#include <vector>
#include <algorithm>  // For reverse function
#include <sstream>    // For stringstream
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[";
    for (size_t i = 0; i < matrix.size(); i++) {  // Use size_t here
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); j++) {  // Use size_t here
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i < matrix.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> matrix;
    string line;
    

    // Reading matrix row by row
    while (getline(cin, line)) {
        if (line.empty()) break;
        stringstream ss(line);
        vector<int> row;
        int num;
        
        while (ss >> num) {
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    Solution solution;
    solution.rotate(matrix);

    printMatrix(matrix);

    return 0;
}