#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        int nse, pse, ele;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                ele = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            nse = n;
            ele = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[ele] * (nse - pse - 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if (r == 0) return 0;
        int c = matrix[0].size();

        vector<int> ps(c, 0);
        int maxi = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == '1') {
                    ps[j]++;
                } else {
                    ps[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(ps));
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    if (rows <= 0) {
        cout << "0" << endl;
        return 0;
    }

    cout << "Enter number of columns: ";
    cin >> cols;
    if (cols <= 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<vector<char>> matrix(rows, vector<char>(cols));
    
    cout << "Enter " << rows << "x" << cols << " matrix of '0' or '1' characters:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != '0' && matrix[i][j] != '1') {
                cout << "Invalid input: only '0' or '1' allowed" << endl;
                return 1;
            }
        }
    }

    // Debug: Print the matrix to confirm input
    cout << "Input matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}