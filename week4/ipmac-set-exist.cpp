//C++ 
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    int elements[size];
    int duplicates[size];
    unordered_set<int> uniqueElements;

    for (int i = 0; i < size; i++) {
        cin >> elements[i];
        if (uniqueElements.find(elements[i]) != uniqueElements.end()) {
            duplicates[i] = 1;
        } else {
            uniqueElements.insert(elements[i]);
            duplicates[i] = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        cout << duplicates[i] << "\n";
    }

    return 0;
}
