#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size(), i = 0;

    while (i < n) {
        int charCount = 0, j = i;

        while (j < n && charCount + words[j].size() + (j - i) <= maxWidth) {
            charCount += words[j].size();
            j++;
        }

        int spaces = maxWidth - charCount;
        int gaps = j - i - 1;
        string line;

        if (j == n || gaps == 0) {
            for (int k = i; k < j; ++k) {
                line += words[k];
                if (k < j - 1) line += " ";
            }
            line += string(maxWidth - line.size(), ' ');
        } else {
            for (int k = i; k < j; ++k) {
                line += words[k];
                if (k < j - 1) {
                    int spaceToAdd = spaces / gaps + ((k - i) < (spaces % gaps) ? 1 : 0);
                    line += string(spaceToAdd, ' ');
                }
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    vector<string> words;

    while (ss >> word)
        words.push_back(word);

    int maxWidth;
    cin >> maxWidth;

    vector<string> res = fullJustify(words, maxWidth);
    for (const string& s : res) {
        cout << "\"" << s << "\"" << endl;
    }

    return 0;
}
