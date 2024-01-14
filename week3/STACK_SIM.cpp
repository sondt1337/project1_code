//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> myStack;
    string cmd;

    while (true) {
        cin >> cmd;
        if (cmd == "#")
            break;
        if (cmd == "PUSH") {
            int value;
            cin >> value;
            myStack.push(value);
        } else if (cmd == "POP") {
            if (myStack.empty())
                cout << "NULL" << endl;
            else {
                cout << myStack.top() << endl;
                myStack.pop();
            }
        }
    }

    return 0;
}
