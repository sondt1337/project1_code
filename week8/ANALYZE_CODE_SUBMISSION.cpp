//C++ 
#include <bits/stdc++.h>
using namespace std;


int toInt(string x) {
    int hour = stoi(x.substr(0, 2));
    int minute = stoi(x.substr(3, 2));
    int second = stoi(x.substr(6, 2));
    return hour * 3600 + minute * 60 + second;
}
int subByTime[90001] = {0};
int error = 0;

int subTime(string start, string end){
    return subByTime[toInt(end)] - subByTime[toInt(start) - 1];
}
int uP[10001][101] = {0};
int main(){
    string datas;
    string user;
    int total = 0;
    int uPoint = 0;
    int uError[10001] = {0};
    while (cin >> datas) {
        if (datas == "#") break;
        else {
            int UID = stoi(datas.substr(1));
            string ProblemID, TimePoint, Status;
            int  Point;
            cin >> ProblemID >> TimePoint >> Status >> Point;
            int PID = stoi(ProblemID.substr(1));
            long long t = toInt(TimePoint);
            total += 1;
            if (Status != "OK") {
                error += 1;
                uError[UID] += 1;
            }
            subByTime[t] += 1;
            if(Point > uP[UID][PID]) uP[UID][PID] = Point;
        }
    }
    for(int i = 1; i < 90001; i++){
        subByTime[i] += subByTime[i - 1];
    }
    while (cin >> datas) {
        if (datas == "#") break;
        else {
            if (datas == "?total_number_submissions") {
                cout << total << endl;
            }
            if (datas == "?number_error_submision") {
                cout << error << endl;
            }
            if (datas == "?number_error_submision_of_user") {
                cin >> user;
                cout << uError[stoi(user.substr(1))] << endl;
            }
            if (datas == "?total_point_of_user") {
                cin >> user;
                int UID = stoi(user.substr(1));
                uPoint = 0;
                for(int i = 0; i < 101; i++){
                    uPoint += uP[UID][i];
                }
                cout << uPoint << endl;
            }
            if (datas == "?number_submission_period") {
                string start, end;
                cin >> start >> end;
                cout << subTime(start, end) << endl;
            }
        }
    }
}
