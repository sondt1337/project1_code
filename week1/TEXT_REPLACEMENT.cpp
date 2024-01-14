// CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string P1, P2, T;
    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);
    while (T.find(P1) != -1)
    {
        T.replace(T.find(P1), P1.length(), P2);
    }
    cout << T << endl;
    return 0;
}
