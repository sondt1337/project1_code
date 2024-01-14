//C++ 
#include <bits/stdc++.h>
using namespace std;
class E {
public:
    int a, b, c;
    E(int a, int b, int c) : a(a), b(b), c(c) {}
};


vector<int> L;

int F(int u) {
    if (L[u] < 0) {
        return u;
    } else {
        return F(L[u]);
    }
}

void U(int u, int v) {
    if (abs(L[u]) < abs(L[v])) {
        swap(u, v);
    }
    L[u] += L[v];
    L[v] = u;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<E> ed;
    L.resize(n + 1, -1);
    int answer = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ed.push_back(E(a, b, c));
    }

    sort(ed.begin(), ed.end(), [](const E& e1, const E& e2) {
        return e1.c < e2.c;
    });

    for (size_t i = 0; i < ed.size(); i++) {
        int a = F(ed[i].a);
        int b = F(ed[i].b);
        if (a != b) {
            U(a, b);
            answer += ed[i].c;
        }
    }

    cout << answer << endl;
    return 0;
}
