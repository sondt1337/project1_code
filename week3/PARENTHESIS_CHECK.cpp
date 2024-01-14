//C++ 
#include <bits/stdc++.h>
using namespace std;

bool check_ck(string s) {
    stack<char> st;
    map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};

    for (char& c : s) {
        if (m.count(c)) {
            if (st.empty() || st.top() != m[c]) return false;
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main() {
    string str;
    cin >> str;
    cout << check_ck(str);
    return 0;
}
