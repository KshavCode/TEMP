#include <iostream>
using namespace std;

// having three consecutive '1's as a substring.

int FA(string input) {
    const int q0_start = 0;
    const int q1 = 1;
    const int q2 = 2;
    const int q3_end = 3;
    int currentState = q0_start;

    for (char ch : input) {
        switch (currentState) {
            case q0_start:
                if (ch == '1') currentState = q1;
                break;
            case q1:
                if (ch == '1') currentState = q2;
                else currentState = q0_start;
                break;
            case q2:
                if (ch == '1') currentState = q3_end;
                else currentState = q0_start;
                break;
            case q3_end:
                break;
        }
    }

    return currentState == q3_end;
}

int main() {
    string inp = "1001110";

    if (FA(inp)) {
        cout << "The string is accepted (contains '111' as a substring)." << endl;
    } else {
        cout << "The string is rejected (does not contain '111' as a substring)." << endl;
    }

}