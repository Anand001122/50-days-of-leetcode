#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

vector<vector<int>> parseMatrix(string input) {
    vector<vector<int>> matrix;
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input = input.substr(1, input.length() - 2);
    stringstream ss(input);
    string row;
    while (getline(ss, row, ']')) {
        if (row.empty()) continue;
        if (row[0] == ',') row = row.substr(1);
        if (row[0] == '[') row = row.substr(1);
        stringstream rowss(row);
        string cell;
        vector<int> rowVec;
        while (getline(rowss, cell, ',')) {
            rowVec.push_back(stoi(cell));
        }
        if (!rowVec.empty()) matrix.push_back(rowVec);
    }
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[";
    for (size_t i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    string input;
    getline(cin, input);
    vector<vector<int>> matrix = parseMatrix(input);
    Solution solution;
    solution.setZeroes(matrix);
    printMatrix(matrix);
    return 0;
}