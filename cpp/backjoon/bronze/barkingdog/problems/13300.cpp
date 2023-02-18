#include <bits/stdc++.h>

using namespace std;

int men[7];
int women[7];

int main(){
    int N, K, rooms;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int gender, grade;
        cin >> gender >> grade;
        if (gender == 0) { women[grade]++; }
        else if (gender == 1) { men[grade]++; }
    }

    rooms = 0;
    for (int i = 1; i <= 6; i++) {
        int m_val = men[i];
        int w_val = women[i];

        rooms += men[i] / K + bool(men[i] % K);
        rooms += women[i] / K + bool(women[i] % K); 
    }

    cout << rooms << "\n";
}