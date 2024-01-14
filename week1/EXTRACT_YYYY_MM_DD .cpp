// CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.size() != 10)
    {
        cout << "INCORRECT";
        return 0;
    }
    for (int i = 0; i < 7; i++)
    {
        if (i == 4)
            i++;
        if (s[i] < 48 || s[i] > 57)
        {
            cout << "INCORRECT";
            return 0;
        }
    }
    if (s[4] != '-' || s[7] != '-')
    {
        cout << "INCORRECT";
        return 0;
    }
    if ((s[5] == '1' && s[6] > 50) || (s[8] == '3' && s[9] > 49) || (s[8] > 50) || s[5] > 49)
    {
        cout << "INCORRECT";
        return 0;
    }
    for (int j = 0; j < 4; j++)
        cout << s[j];
    if (s[5] == '0')
        cout << " " << s[6] << " ";
    else
        cout << " " << s[5] << s[6] << " ";
    if (s[8] == '0')
        cout << s[9];
    else
        cout << s[8] << s[9];
}
