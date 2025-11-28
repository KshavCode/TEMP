#include <iostream>
using namespace std;

// EVEN-EVEN language

void simulateFA(string input) {
    // q0: Even 'a's, Even 'b's (Start, Accept)
    // q1: Odd 'a's,  Even 'b's
    // q2: Even 'a's, Odd 'b's
    // q3: Odd 'a's,  Odd 'b's
    const int q0_start = 0;
    const int q1 = 1;
    const int q2 = 2;
    const int q3 = 3;

    int currentState = q0_start; // Start in q0

    // Process each character in the input string
    for (char ch : input) {
        if (ch != 'a' && ch != 'b') {
        cout << "Result: Rejected" << endl;
        }

        switch (currentState) {
            case q0_start: // Even-a, Even-b
                if (ch == 'a') {
                    currentState = q1; 
                } else { 
                    currentState = q2; 
                }
                break;
            case q1: // Odd-a, Even-b
                if (ch == 'a') {
                    currentState = q0_start;
                } else {
                    currentState = q3; 
                }
                break;
            case q2: // Even-a, Odd-b
                if (ch == 'a') {
                    currentState = q3;
                } else { 
                    currentState = q0_start; 
                }
                break;
            case q3: // Odd-a, Odd-b
                if (ch == 'a') {
                    currentState = q2;
                } else { 
                    currentState = q1; 
                }
                break;
        }
    }

    cout << "Input: \"" << input << "\" ->\t";
    if (currentState == q0_start) {
        cout << "Result: Accepted" << endl;
    } else {
        cout << "Result: Rejected" << endl;
    }
}

int main() {
    // Test cases for EVEN-EVEN language
    simulateFA("");       // Accepted (0 a's, 0 b's)
    simulateFA("aa");     // Accepted (2 a's, 0 b's)
    simulateFA("bb");     // Accepted (0 a's, 2 b's)
    simulateFA("aabb");   // Accepted (2 a's, 2 b's)
    simulateFA("abab");   // Accepted (2 a's, 2 b's)
    simulateFA("baba");   // Accepted (2 a's, 2 b's)
    simulateFA("a");      // Rejected (1 a, 0 b)
    simulateFA("b");      // Rejected (0 a, 1 b)
    simulateFA("ab");     // Rejected (1 a, 1 b)
    simulateFA("aab");    // Rejected (2 a, 1 b)
    simulateFA("bba");    // Rejected (1 a, 2 b)
    simulateFA("bababa"); // Rejected (3 a, 3 b)

    return 0;
}