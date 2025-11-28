#include <iostream>
#include <string>
using namespace std;

// String starts and ends with the same two characters
void FA(string input) {
    const int Q0_start = 0; 
    const int Q1 = 1; // Read first character
    const int Q2_end = 2; // Read second character

    int currentState = Q0_start;
    char firstChar;
    char secondChar;

    for (int i = 0; i < input.length(); ++i) {
        char ch = input[i];
        switch (currentState) {
            case Q0_start:
                firstChar = ch;
                currentState = Q1;
                break;
            case Q1:
                secondChar = ch;
                currentState = Q2_end;
                break;
            case Q2_end:
                break;
        }
    }

    if (input.length() >= 4 && 
        firstChar == input[input.length() - 2] && secondChar == input[input.length() - 1]) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }
}

int main() {
    string inp1 = "abab";
    FA(inp1); // Should be accepted

    string inp2 = "bbaaaabb";
    FA(inp2); // Should be accepted
    
    string inp3 = "abba";
    FA(inp3); // Should be rejected

     string inp4 = "aab";
    FA(inp4); // Rejected (Length < 4)
}

