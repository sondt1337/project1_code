//C++ 
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

unordered_map<string, unordered_set<string>> adj;
set<string> bank_accounts;
unordered_set<string> flag;
unordered_map<string, int> transferred_money;
int count_trans = 0;
int total_money = 0;
int res = 0;
string root_acc = "";

void check_cycle(const string& from_acc, int k) {
    if (res) {
        return;
    }

    for (const auto& acc : adj[from_acc]) {
        if (k == 1) {
            if (acc == root_acc) {
                res = 1;
                return;
            }
            continue;
        }

        if (flag.find(acc) == flag.end()) {
            flag.insert(acc);
            check_cycle(acc, k - 1);
            flag.erase(acc);
        }
    }
}

int main() {
    string src;
    cin >> src;

    while (src != "#") {
        string dest, money_str, time, atm;
        cin >> dest >> money_str >> time >> atm;
        int money = stoi(money_str);

        count_trans += 1;
        total_money += money;

        bank_accounts.insert(src);
        bank_accounts.insert(dest);

        transferred_money[src] += money;

        adj[src].insert(dest);

        cin >> src;
    }

    string query;
    cin >> query;

    while (query != "#") {
        if (query == "?number_transactions") {
            cout << count_trans << endl;
        } else if (query == "?total_money_transaction") {
            cout << total_money << endl;
        } else if (query == "?list_sorted_accounts") {
            for (const auto& acc : bank_accounts) {
                cout << acc << " ";
            }
            cout << endl;
        } else if (query == "?total_money_transaction_from") {
            string src_acc;
            cin >> src_acc;
            cout << transferred_money[src_acc] << endl;
        } else if (query == "?inspect_cycle") {
            string from_acc;
            int k;
            cin >> from_acc >> k;
            root_acc = from_acc;
            res = 0;
            flag.clear();
            flag.insert(root_acc);
            check_cycle(from_acc, k);
            cout << (res ? "1" : "0") << endl;
        }

        cin >> query;
    }

    return 0;
}
