//C++
#include <bits/stdc++.h>
using namespace std;
int B[100] = {0};

void try_(int x, int n, int number[])
{
    for (int i = 1; i <= n; i++)
    {
        if (!B[i])
        {
            number[x] = i;
            B[i] = 1;
            if (x == n)
            {
                for (int j = 1; j <= n; j++)
                    cout << number[j] << " ";
                cout << "\n";
            }
            else
                try_(x + 1, n, number);
            B[i] = 0;
        }
    }
}

void gen(int n)
{
    int number[100];
    for (int i = 1; i <= n; i++)
        number[i - 1] = i;
    try_(1, n, number);
}

int main()
{
    int n;
    cin >> n;
    gen(n);
    return 0;
}
