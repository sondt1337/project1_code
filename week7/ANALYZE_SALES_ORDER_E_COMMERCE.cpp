//C++ 
//C++ 
#include <bits/stdc++.h>
using namespace std;
// Đinh Thái Sơn - 20210750
struct Purchase {
    string customer, item, vendor, tim3;
    int cost;
};

unordered_map<string, int> customerExpenditure, vendorIncome;
set<int> transactiontim3s;
int totalTransactions = 0, totalIncome = 0, incomeOverTime[90000];

int timeToSeconds(const string& tim3) {
    return stoi(tim3.substr(0, 2)) * 3600 + stoi(tim3.substr(3, 2)) * 60 + stoi(tim3.substr(6, 2));
}

void handlePurchase(const Purchase& purchase) {
    totalTransactions++;
    vendorIncome[purchase.vendor] += purchase.cost;
    customerExpenditure[purchase.customer + purchase.vendor] += purchase.cost;

    incomeOverTime[timeToSeconds(purchase.tim3)] += purchase.cost;
    transactiontim3s.insert(timeToSeconds(purchase.tim3));
}

void computeCumulativeIncome() {
    int temp = 0;
    for (int t : transactiontim3s) {
        incomeOverTime[t] += temp;
        temp = incomeOverTime[t];
    }
    totalIncome = temp;
    for (int i = 1; i <= 86400; ++i) {
        if (!incomeOverTime[i]) incomeOverTime[i] = incomeOverTime[i - 1];
    }
}

void handleInstruction(const string& instruction) {
    if (instruction == "?total_number_orders") 
        cout << totalTransactions;
    else if (instruction == "?total_revenue") 
        cout << totalIncome;
    else if (instruction == "?revenue_of_shop") {
        string vendor;
        cin >> vendor;
        cout << vendorIncome[vendor];
    }
    else if (instruction == "?total_consume_of_customer_shop") {
        string customer, vendor;
        cin >> customer >> vendor;
        cout << customerExpenditure[customer + vendor];
    }
    else if (instruction == "?total_revenue_in_period") {
        string tim31, tim32;
        cin >> tim31 >> tim32;
        int t1 = timeToSeconds(tim31), t2 = timeToSeconds(tim32);
        cout << incomeOverTime[t2] - incomeOverTime[t1 - 1];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    vector<Purchase> purchases;
    Purchase currentPurchase;

    cin >> currentPurchase.customer;
    while (currentPurchase.customer != "#") {
        cin >> currentPurchase.item >> currentPurchase.cost >> currentPurchase.vendor >> currentPurchase.tim3;
        purchases.push_back(currentPurchase);
        cin >> currentPurchase.customer;
    }

    for (const auto& purchase : purchases) {
        handlePurchase(purchase);
    }

    computeCumulativeIncome();

    string instruction;
    cin >> instruction;
    while (instruction != "#") {
        handleInstruction(instruction);
        cin >> instruction;
    }

    return 0;
}
