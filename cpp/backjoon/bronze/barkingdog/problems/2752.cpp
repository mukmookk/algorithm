#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int ret[3];

    ret[0] = min({A, B, C});
    ret[2] = max({A, B, C});
    ret[1] = A + B + C - ret[0] - ret[2];

    cout << ret[0] << " " << ret[1] << " " << ret[2];
}