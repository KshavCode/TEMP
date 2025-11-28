#include <bits/stdc++.h>
using namespace std;

// a(a+b)*b
string FA(string w)
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

    if (state == 2)
        return "Accepted";
    else
        return "Rejected";
}

int main()
{
    string w;
    cout << "Give the string to be checked : ";
    cin >> w;

    cout << "Result : " << FA(w) << endl;
    return 0;
}
