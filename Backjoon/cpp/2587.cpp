#include <bits/stdc++.h>

using namespace std;

int main() {
    int nums, median;

    double sum;
    vector<int> vec;

    for (int i = 0; i < 5; i++) {
        cin >> nums;
        vec.push_back(nums);
        sum += nums;
    }

    sort(vec.begin(), vec.end());

    median = floor(vec.size() / 2.0);

    cout << sum / vec.size() << "\n" << vec[median] << "\n";
}