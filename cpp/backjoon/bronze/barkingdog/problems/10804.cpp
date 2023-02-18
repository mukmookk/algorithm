#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cards[20];

    for (int i = 1; i <= 20; i++) {
        cards[i - 1] = i;
    }

    for (int n = 0; n < 10; n++) {
        int i, j;
        cin >> i >> j;
        reverse(cards + i - 1, cards + j);
    }

    for (int i = 0; i < 20; i++) cout << cards[i] << " ";
}