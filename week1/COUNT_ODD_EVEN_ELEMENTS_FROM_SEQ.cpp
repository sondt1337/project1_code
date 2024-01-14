// CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[100000], even_count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even_count++;
    }
    cout << n - even_count << " " << even_count;
}
