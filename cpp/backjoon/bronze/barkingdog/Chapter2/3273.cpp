#include <bits/stdc++.h>

using namespace std;

int nums[10000001] = {0,};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, val, total;
    vector<int> keys;

    cin >> n;
    for (int i = 0; i < n; i++) { cin >> val; nums[val]++; keys.push_back(val); }
    cin >> x;

    total = 0;
    for (int i = 0; i < n; i++) {
        if (x - keys[i] <= 0)
            continue;
        
        if (x == 2 * keys[i]) {
            if (nums[keys[i]] > 1)
                total++;
        }
        else if (nums[x - keys[i]]) {
            // cout << keys[i] << "\n";
            total++;
            nums[x - keys[i]]--;
            nums[keys[i]]--;
        }
    }
    cout << total << "\n";
}