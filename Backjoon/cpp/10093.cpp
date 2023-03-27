#include <bits/stdc++.h>

using namespace std;

int main() {
    long long A, B;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    // 순서
    if (A > B)
        swap(A, B);

    // 둘 사이에 숫자가 없다면 0을 출력하라는데, 문제는 별다른 서술이 없다
    if (A == B || B  - A == 1) {
        cout << 0;
        return 0;
    }
    
    cout << B - A - 1 << "\n";
    for (long long i = A + 1; i < B; i++) {
        cout << i << " ";
    }
}