// CPP
#include <bits/stdc++.h>
using namespace std;
int find_max(int a[], int n)
{
    int maximum = -1001;
    for (int i = 0; i < n; i++)
    {
        if (maximum < a[i])
            maximum = a[i];
    }
    return maximum;
}

int find_min(int a[], int n)
{
    int minimum = 1001;
    for (int i = 0; i < n; i++)
    {
        if (minimum > a[i])
            minimum = a[i];
    }
    return minimum;
}

int find_max_segment(int a[], int x, int y)
{
    int maximum = -1001;
    for (int i = x - 1; i < y; i++)
    {
        if (maximum < a[i])
            maximum = a[i];
    }
    return maximum;
}
int main()
{
    int n, sum = 0;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    string command;
    cin >> command;
    while (command != "***")
    {
        cin >> command;
        if (command == "find-max")
            cout << find_max(a, n) << endl;
        if (command == "find-min")
            cout << find_min(a, n) << endl;
        if (command == "find-max-segment")
        {
            int x, y;
            cin >> x >> y;
            cout << find_max_segment(a, x, y) << endl;
        }
        if (command == "sum")
            cout << sum << endl;
    }
}
