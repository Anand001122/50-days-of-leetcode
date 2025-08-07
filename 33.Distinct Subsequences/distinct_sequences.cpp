#include <iostream>
#include <cstring>
using namespace std;

int solve(int index1, int index2, char *str1, char *str2) {
    if (index2 < 0) {
        return 1;
    }
    if (index1 < 0) {
        return 0;
    }
    if (str1[index1] == str2[index2]) {
        return solve(index1 - 1, index2 - 1, str1, str2) + solve(index1 - 1, index2, str1, str2);
    }
    return solve(index1 - 1, index2, str1, str2);
}

int numDistinct(char *s, char *t) {
    int n1 = strlen(s);
    int n2 = strlen(t);
    return solve(n1 - 1, n2 - 1, s, t);
}

int main() {
    char s[1000], t[1000];

    // Taking user input for strings s and t
    cin >> s;
    
    cin >> t;
    
    cout << "Number of distinct subsequences: " << numDistinct(s, t) << endl;  // Output the result
    return 0;
}
