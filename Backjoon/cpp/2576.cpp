#include <bits/stdc++.h>

using namespace std;

int main() {
    int nums, sum, min;

    sum = 0;
    min = INT_MAX;

    for (int i = 0; i < 7; i++) {
        cin >> nums;
            sum += nums;
            if (min > nums)
                min = nums;
        }
    }
    if (sum)
        cout << sum << "\n" << min;
    else
        cout << -1;
}