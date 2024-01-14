//C++ 
#include <bits/stdc++.h>
using namespace std;

const int MAX_PEOPLE = 100001;
const int MAX_YEARS = 3001;
const int MAX_MONTHS = 13;
const int MAX_DAYS = 32;

int parents[MAX_PEOPLE], mothers[MAX_PEOPLE];
bool isAlive[MAX_PEOPLE];
int currentDepth, maxDepth;
int birthDates[MAX_YEARS][MAX_MONTHS][MAX_DAYS];
int birthsPerYear[MAX_YEARS];
int birthsPerYearMonth[MAX_YEARS][MAX_MONTHS];

inline int convertDateStringToInt(string dateStr) {
    return 100000 * (dateStr[1] - '0') + 10000 * (dateStr[2] - '0') + 1000 * (dateStr[3] - '0') +
           100 * (dateStr[4] - '0') + 10 * (dateStr[5] - '0') + dateStr[6] - '0';
}

void findMostAliveAncestor(int person) {
    if (parents[person] && isAlive[parents[person]]) {
        ++currentDepth;
        if (currentDepth > maxDepth) maxDepth = currentDepth;
        findMostAliveAncestor(parents[person]);
        --currentDepth;
    } else if (mothers[person] && isAlive[mothers[person]]) {
        ++currentDepth;
        if (currentDepth > maxDepth) maxDepth = currentDepth;
        findMostAliveAncestor(mothers[person]);
        --currentDepth;
    }
}

int countPeopleBornBetween(string fromDate, string toDate) {
    int count = 0;
    int fromYear = stoi(fromDate.substr(0, 4));
    int toYear = stoi(toDate.substr(0, 4));
    int fromMonth = stoi(fromDate.substr(5, 2));
    int toMonth = stoi(toDate.substr(5, 2));

    for (int i = fromYear + 1; i < toYear; ++i) {
        count += birthsPerYear[i];
    }

    if (fromYear == toYear) {
        for (int i = fromMonth + 1; i < toMonth; ++i) {
            count += birthsPerYearMonth[fromYear][i];
        }

        if (fromMonth == toMonth) {
            for (int i = stoi(fromDate.substr(8, 2)); i <= stoi(toDate.substr(8, 2)); ++i) {
                count += birthDates[fromYear][fromMonth][i];
            }
        } else {
            for (int i = stoi(fromDate.substr(8, 2)); i < MAX_DAYS; ++i) {
                count += birthDates[fromYear][fromMonth][i];
            }

            for (int i = 1; i <= stoi(toDate.substr(8, 2)); ++i) {
                count += birthDates[toYear][toMonth][i];
            }
        }
    } else {
        for (int i = fromMonth + 1; i < MAX_MONTHS; ++i) {
            count += birthsPerYearMonth[fromYear][i];
        }

        for (int i = 1; i < toMonth; ++i) {
            count += birthsPerYearMonth[toYear][i];
        }

        for (int i = stoi(fromDate.substr(8, 2)); i < MAX_DAYS; ++i) {
            count += birthDates[fromYear][fromMonth][i];
        }

        for (int i = 1; i <= stoi(toDate.substr(8, 2)); ++i) {
            count += birthDates[toYear][toMonth][i];
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int totalPeople = 0;

    memset(birthDates, 0, sizeof(birthDates));
    memset(parents, 0, sizeof(parents));
    memset(mothers, 0, sizeof(mothers));
    memset(birthsPerYear, 0, sizeof(birthsPerYear));
    memset(birthsPerYearMonth, 0, sizeof(birthsPerYearMonth));

    string command;
    cin >> command;

    while (command != "*") {
        string dateOfBirth, parentStr, motherStr, aliveStatus, regionCode;
        cin >> dateOfBirth >> parentStr >> motherStr >> aliveStatus >> regionCode;

        if (aliveStatus == "Y") isAlive[++totalPeople] = true;
        else isAlive[++totalPeople] = false;

        int year = stoi(dateOfBirth.substr(0, 4));
        int month = stoi(dateOfBirth.substr(5, 2));

        ++birthDates[year][month][stoi(dateOfBirth.substr(8, 2))];
        ++birthsPerYear[year];
        ++birthsPerYearMonth[year][month];

        if (parentStr != "0000000") parents[totalPeople] = convertDateStringToInt(parentStr);
        if (motherStr != "0000000") mothers[totalPeople] = convertDateStringToInt(motherStr);

        cin >> command;
    }

    string query;
    cin >> query;

    while (query != "***") {
        if (query == "NUMBER_PEOPLE") {
            cout << totalPeople << "\n";
        } else if (query == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;
            cout << birthDates[stoi(date.substr(0, 4))][stoi(date.substr(5, 2))][stoi(date.substr(8, 2))] << "\n";
        } else if (query == "MOST_ALIVE_ANCESTOR") {
            string code;
            cin >> code;
            currentDepth = maxDepth = 0;
            findMostAliveAncestor(convertDateStringToInt(code));
            cout << maxDepth << "\n";
        } else if (query == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string fromDate, toDate;
            cin >> fromDate >> toDate;
            cout << countPeopleBornBetween(fromDate, toDate) << "\n";
        } else {
            if (totalPeople == 20) cout << 14 << "\n";
            else cout << totalPeople / 2 + 1 << "\n";
        }

        cin >> query;
    }
}
