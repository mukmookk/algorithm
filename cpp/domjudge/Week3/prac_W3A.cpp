#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> medianSlidingWindow(vector<int> &nums, int d) {
    vector<double> medians;

    for (int i = 0; i + d < nums.size(); i++) {
        vector<int> window(nums.begin() + i, nums.begin() + i + d);

        sort(window.begin(), window.end());

        if (d & 1)
            medians.push_back(window[d / 2]);
        else
            medians.push_back((window[d / 2] + window[d / 2 - 1]) / 2.0);
    }
    return medians;
}

void cases() {
    int n, d, cal, count;

    vector<int> calories;
    vector<double> medians;
    cin >> n >> d;
    count = 0;
    for (int i = 0; i < n; i++) {
        cin >> cal;
        calories.push_back(cal);
    }
    medians = medianSlidingWindow(calories, d);
    for (int i = 0; i + d < n; i++) {
        if (calories[i + d] >= 2 * medians[i]) {
            count = count + 1;
        }
    }
    cout << count << "\n";
}

int main()
{
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}