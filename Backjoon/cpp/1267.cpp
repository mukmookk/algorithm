#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, num, Y, M;
    Y = M = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        
        // ceil이나 floor 함수 쓸 경우에는 항상 소수점 붙여줘야 계산이 가능
        Y += (ceil(num / 30.0) * 10);
        M += (ceil(num / 60.0) * 15);

        if (num % 30 == 0) Y += 10;
        if (num % 60 == 0) M += 15; 
    }

    if (Y == M)
        cout << "Y" << " " << "M" << " " << Y;
    else if (Y < M)
        cout << "Y" << " " << Y;
    else if (M < Y)
        cout << "M" << " " << M;   
}