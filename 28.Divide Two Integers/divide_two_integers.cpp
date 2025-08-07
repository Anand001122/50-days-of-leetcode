#include <iostream>
#include <cmath>
#include <climits>  // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) != (divisor < 0);

        // Work with absolute values
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        int quotient = 0;

        // Subtract divisor from dividend using bit shifts
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            int multiple = 1;
            while (absDividend >= (temp << 1)) {  // Shift left (doubling) to speed up the process
                temp <<= 1;
                multiple <<= 1;
            }
            absDividend -= temp;
            quotient += multiple;
        }

        // Return the quotient with appropriate sign
        return negative ? -quotient : quotient;
    }
};

int main() {
    // Reading input from the user
    int dividend, divisor;
    cin >> dividend;
    cin >> divisor;

    // Create a Solution instance and compute the result
    Solution solution;
    int result = solution.divide(dividend, divisor);

    // Output the result
    cout<< result << endl;

    return 0;
}