// CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    double delta;
    double nghiem1, nghiem2;
    cin >> a >> b >> c;
    delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    else if (delta == 0)
        cout << fixed << setprecision(2) << ((-1) * b / (2 * a)) * 0.01 * 100;
    else
        cout << fixed << setprecision(2) << ((-1) * b - sqrt(delta)) / (2 * a) * 0.01 * 100 << " " << ((-1) * b + sqrt(delta)) / (2 * a) * 0.01 * 100;
}
