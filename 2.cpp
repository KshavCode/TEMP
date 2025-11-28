#include <iostream>
using namespace std;

//either exactly two '1's or exactly three '1's as substrings, not more nor less

int FA(string input) {
    const int q0_start = 0; // 0 '1's seen
    const int q1 = 1; // 1 '1' seen
    const int q2 = 2; // 2 '1's seen
    const int q3 = 3; // 3 '1's seen
    const int q4_end = 4; // more than 3 '1's seen
    int currentState = q0_start;

    for (char ch : input) {
        switch (currentState) {
            case q0_start:
                if (ch == '1') currentState = q1;
                break;
            case q1:
                if (ch == '1') currentState = q2;
                break;
            case q2:
                if (ch == '1') currentState = q3;
                break;
            case q3:
                if (ch == '1') currentState = q4_end;
                break;
            case q4_end:
                break;
        }
    }

    return currentState == q2 || currentState == q3;
}

int main() {
    string inp = "100";

    if (FA(inp)) {
        cout << "The string is accepted (contains exactly two or three '1's)." << endl;
    } else {
        cout << "The string is rejected (does not contain exactly two or three '1's)." << endl;
    }

}

