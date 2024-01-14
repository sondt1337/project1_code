// CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int x;
    cin >> s;
    if (s.size() != 8)
    {
        cout << "INCORRECT";
        return 0;
    }
    if (s[2] != ':' || s[5] != ':')
    {
        cout << "INCORRECT";
        return 0;
    }
    if ((s[0] == 50 && s[1] > 52) || (s[0] > 50) || s[3] > 53 || s[6] > 53)
    {
        cout << "INCORRECT";
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        x = ((s[0] - 48) * 10 + s[1] - 48) * 3600 + ((s[3] - 48) * 10 + s[4] - 48) * 60 + ((s[6] - 48) * 10 + s[7] - 48);
    }
    cout << x;
}
