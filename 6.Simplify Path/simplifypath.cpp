#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string dir;
        
        while (getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(dir);
            }
        }

        string res;
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main() {
    string path;
    getline(cin, path);
    Solution sol;
    cout << sol.simplifyPath(path);
    return 0;
}
