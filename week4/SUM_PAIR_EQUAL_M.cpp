//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num, target;
    cin >> num >> target;
    vector<int> numbers(num);
    int pairs = 0;
    unordered_set<int> elements;
    
    for (int i = 0; i < num; i++){
        cin >> numbers[i];
        elements.insert(numbers[i]);
    }
    
    for (auto element:elements){
        if(elements.count(target - element) > 0) {
            pairs++;
        }
    }
    
    cout << pairs / 2;
}
