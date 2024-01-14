//C++ 
#include <bits/stdc++.h>
using namespace std;

set<string> secret_container;

void scan() {
    string s_s;
    while (cin >> s_s) {
        if (s_s != "*") {
            secret_container.insert(s_s);
        } else {
            break;
        }
    }
}

int search(string s_s) {
    if (secret_container.count(s_s) > 0) {
        return 1;
    }
    return 0;
}

int ins(string s_s) {
    if (secret_container.count(s_s) > 0) {
        return 0;
    }
    secret_container.insert(s_s);
    return 1;
}

int main() {
    scan();
    string cmd;
    while (cin >> cmd) {
        string s_s;
        cin >> s_s;
        if (cmd == "find") {
            cout << search(s_s) << endl;
        }
        if (cmd == "insert") {
            cout << ins(s_s) << endl;
        }
        if (cmd == "*") {
            break;
        }
    }
}
