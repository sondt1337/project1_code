//C++ 
#include <bits/stdc++.h> 

using namespace std;

struct HashCalculator {
    static int calculate(const string& input, int modulo) {
        int hashValue = 0;

        for (char c : input) {
            hashValue = (hashValue * 256 + c) % modulo;
        }

        return hashValue;
    }
};

int main() {
    int numberOfInputs, moduloValue;
    cin >> numberOfInputs >> moduloValue;

    vector<string> inputs(numberOfInputs);
    for (int i = 0; i < numberOfInputs; i++) {
        cin >> inputs[i];
    }

    for (const string& input : inputs) {
        int calculatedHash = HashCalculator::calculate(input, moduloValue);
        cout << calculatedHash << '\n';
    }

    return 0;
}
