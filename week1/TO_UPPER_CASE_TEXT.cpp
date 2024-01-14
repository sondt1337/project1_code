#include <iostream>
using namespace std;

int main()
{
    string s;
    int count = 0;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = toupper(s[i]);
        }
        cout << s << endl;
    }

    return 0;
}
