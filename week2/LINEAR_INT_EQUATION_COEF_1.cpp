//C++ 
#include <bits/stdc++.h>
using namespace std;

void printnghiem(const vector<int>& nghiem) {
    for (int value : nghiem)
        cout << value << " ";
    cout << endl;
}
void gen_co(int n, int M, vector<int>& curr, int tong) {
    if (n == 0) {
        if (tong == 0) {
            printnghiem(curr);
        }
        return;
    }
    for (int j = 1; j <= M; j++) {
        if (j <= tong) {
            curr.push_back(j);
            gen_co(n - 1, M, curr, tong - j);
            curr.pop_back();
        }
    }
}
int main() {
    int n, M;
    cin >> n >> M;
    vector<int> curr;
    gen_co(n, M, curr, M);
    return 0;
}
