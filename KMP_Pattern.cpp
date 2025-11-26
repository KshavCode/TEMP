#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(const string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text); 

    if (text.empty()) {
        getline(cin, text);
    }

    cout << "Enter pattern: ";
    getline(cin, pattern);

    if (pattern.empty()) {
        cout << "Pattern is empty.\n";
        return 0;
    }

    vector<int> lps = buildLPS(pattern);

    int n = text.size();
    int m = pattern.size();
    int i = 0; // index for text
    int j = 0; // index for pattern

    vector<int> occurrences;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (occurrences.empty()) {
        cout << "Pattern not found\n";
    } else {
        cout << "Pattern found at indices (0-based): ";
        for (int idx : occurrences) cout << idx << " ";
        cout << "\n";
    }

    return 0;
}
