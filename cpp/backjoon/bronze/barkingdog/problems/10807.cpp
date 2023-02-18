#include <bits/stdc++.h>

using namespace std;

int positive[101] = {0,};
int negative[101] = {0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, val, total;

    cin >> n;
    for (int i = 0; i < n; i++) { 
        cin >> val;
        if (val > 0)
            positive[val]++;
        else
            negative[-1 * val]++;
    } 
    cin >> x;

    if (x > 0)
        cout << positive[x] << "\n";
    else
        cout << negative[-1 * x] << "\n";
}