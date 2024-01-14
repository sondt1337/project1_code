//C++ 
#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> cayGiaPha;
map<string, string> toTien;

void themThanhVien(string con, string cha) {
    cayGiaPha[cha].push_back(con);
}

int tinhSoConChau(string tenThanhVien) {
    int tong = cayGiaPha[tenThanhVien].size();
    for(auto con : cayGiaPha[tenThanhVien]) {
        tong += tinhSoConChau(con);
    }
    return tong;
}

int tinhSoTheHe(string tenThanhVien) {
    if(cayGiaPha[tenThanhVien].empty()) return 0;
    int soTheHeMax = 0;
    for(auto con : cayGiaPha[tenThanhVien]) {
        soTheHeMax = max(soTheHeMax, tinhSoTheHe(con));
    }
    return 1 + soTheHeMax;
}

int main() {
    string inp;
    while(getline(cin, inp) && inp != "***") {
        stringstream ss(inp);
        string con, cha;
        ss >> con >> cha;
        themThanhVien(con, cha);
    }
    
    while(getline(cin, inp) && inp != "***") {
        stringstream ss(inp);
        string lenh, tenThanhVien;
        ss >> lenh >> tenThanhVien;
        if(lenh == "descendants") {
            cout << tinhSoConChau(tenThanhVien) << endl;
        } else if(lenh == "generation") {
            cout << tinhSoTheHe(tenThanhVien) << endl;
        }
    }
    
    return 0;
}
