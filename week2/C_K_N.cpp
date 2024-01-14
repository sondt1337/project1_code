// C++
#include <bits/stdc++.h>
using namespace std;
const long long x = 1e9 + 7;

long long inv(long long i, long long m)
{
    long long a = m;
    long long y = 0, x = 1;
    while (i > 1)
    {
        long long t = m, q = i / m;
        m = i % m;
        i = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        return x + a;
    return x;
}

long long Tinhtoan(int k, int n)
{
    long long res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; i++)
    {
        res = res * (n - i) % x;
        res = res * inv(1 + i, x) % x;
    }
    return res;
}

int main()
{
    long long n, k;
    cin >> k >> n;
    cout << Tinhtoan(k, n);
}
