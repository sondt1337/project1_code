//C++ 
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
        int count = 0;
        bitset<20> bin_seq(i);
        string seq_str = bin_seq.to_string().substr(20 - n);
        for (int j = 1; j < seq_str.size(); j++)
        {
            if (seq_str[j - 1] == '1' && seq_str[j] == '1')
            {
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << seq_str << endl;
    }
}
