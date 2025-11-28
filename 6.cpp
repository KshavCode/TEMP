
#include <bits/stdc++.h>
using namespace std;

bool L1(string w)
{
    int n = w.length();
    if (n < 4)
        return false;
    if (w[0] == w[n - 2] && w[1] == w[n - 1])
        return true;
    return false;
}

bool L2(string w)
{
    int state = 0;
    for (int i = 0; i < (int)w.length(); i++)
    {
        char c = w[i];
        switch (state)
        {
            case 0:
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 3;
                break;

            case 1:
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                break;

            case 2:
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                break;

            case 3:
                if (c == 'a' || c == 'b')
                    state = 3;
                break;
        }
    }
    return state == 2;
}

string FA_union(string w)
{
    if (L1(w) || L2(w))
        return "Accepted";
    else
        return "Rejected";
}

string FA_intersection(string w)
{
    if (L1(w) && L2(w))
        return "Accepted";
    else
        return "Rejected";
}

string FA_concat(string w)
{
    int n = w.length();
    for (int i = 0; i <= n; i++)
    {
        string x = w.substr(0, i);
        string y = w.substr(i);
        if (L1(x) && L2(y))
            return "Accepted";
    }
    return "Rejected";
}

int main()
{
    string w;
    int choice;
    cout << "1. Union L1 U L2\n";
    cout << "2. Intersection L1 n L2\n";
    cout << "3. Concatenation L1.L2\n";
    cout << "Enter choice: ";
    cin >> choice;
    cout << "Give the string to be checked : ";
    cin >> w;

    if (choice == 1)
        cout << "Result : " << FA_union(w) << endl;
    else if (choice == 2)
        cout << "Result : " << FA_intersection(w) << endl;
    else if (choice == 3)
        cout << "Result : " << FA_concat(w) << endl;
    else
        cout << "Invalid choice\n";

    return 0;
}
