//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int n;
    cin >>n;
    for (int i = 100; i< 1000; i++){
        if (i % n == 0){
            cout << i << " ";
        }
    } 
}
