//C++ 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "PUSH")
        {
            int value;
            cin >> value;
            q.push(value);
        }
        else if (cmd == "POP")
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
                cout << "NULL" << endl;
        }
        else if (cmd == "#")
            break;
    }
    return 0;
}
