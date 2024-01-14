#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
        cout << "0";
    cout << "\n";

    for (int i = 1; i < pow(2, n); i++)
    {
        bitset<20> bin_seq(i);
        string seq_str = bin_seq.to_string().substr(20 - n);
        cout << seq_str << endl;
    }
}
