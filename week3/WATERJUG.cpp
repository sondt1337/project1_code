//C++ 
#include <bits/stdc++.h>
using namespace std;

int greatestCommonDivisor(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    return greatestCommonDivisor(num2, num1 % num2);
}

int solve(int sideA, int sideB, int target)
{
    if (sideA > sideB)
        swap(sideA, sideB);
    if (target > sideB)
        return -1;
    if (target % greatestCommonDivisor(sideA, sideB) != 0)
        return -1;

    int steps = 1;
    int X = sideA, Y = 0;

    while (X != target && Y != target)
    {
        int temp = min(X, sideB - Y);
        Y += temp;
        X -= temp;
        steps++;
        if (X == target || Y == target)
            break;
        if (X == 0)
        {
            X = sideA;
            steps++;
        }
        if (Y == sideB)
        {
            Y = 0;
            steps++;
        }
    }
    return steps;
}

int main()
{
    int sideA, sideB, target;
    cin >> sideA >> sideB >> target;
    cout << solve(sideA, sideB, target);
    return 0;
}
