#include <bits/stdc++.h>

using namespace std;

int nums[1000] = {};

int main() {
    int a, b, c, res;
    string s_res;

    cin >> a >> b >> c;

    res = a * b * c;
    s_res = to_string(res);

    for (int i = 0; i < 10; i++) {
        nums[s_res[i]]++;
    }

    for (int i = 0; i < 10; i++) {
        cout << nums[48 + i] << "\n";
    }
}