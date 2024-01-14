// CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[100000], b[100000] = {0}, cnt = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        b[x] += a[i];
    }
    if (b[x] % 2 == 0)
        cnt++;
    for (int i = 0; i < n - k; i++)
    {
        x++;
        b[x] = b[x-1] - a[i] + a[i + k];   
        if (b[x] % 2 == 0)
            cnt++;
    }
    cout << cnt;
}
