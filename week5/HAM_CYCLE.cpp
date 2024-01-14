//C++ 
#include <bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> kt(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            kt[u][v] = 1;
            kt[v][u] = 1;
        }

        vector<int> test;
        for (int i = 1; i <= n; i++) {
            test.push_back(i);
        }

        bool found = false;
        do {
            bool ch = true;
            for (int i = 1; i < n; i++) {
                ch = ch && kt[test[i - 1]][test[i]];
            }
            ch = ch && kt[test[n - 1]][test[0]];

            if (ch) {
                found = true;
                break;
            }
        } while (next_permutation(test.begin(), test.end()));

        cout << found << endl;
    }

    return 0;
}
