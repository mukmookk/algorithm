#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<double> slidingMedianWindow(vector<int> &calories, int d) {
    vector<double> medians;

    for (int i = 0; i + d <= calories.size(); i++) {
        vector<int> window(calories.begin() + i, calories.begin() + i + d);

        sort(window.begin(), window.end());
        if (d % 2 == 1)
            medians.push_back(window[d / 2]);
        else
            medians.push_back((window[d / 2] + window[d / 2 - 1]) / 2.0);
    }
    return medians;
}

void cases() {
    vector<int> calories;
    vector<double> medians;

    int n, d, cal, count;

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> cal;
        calories.push_back(cal);
    }
    medians = slidingMedianWindow(calories, d);

    count = 0;
    for (int i = 0; i + d < n; i++) {
        if (calories[i + d] >= medians[i] * 2)
            count = count + 1;
    }

    cout << count << "\n";
}

int main() {
    int T;

    cin >> T;
    while(T--) {
        cases();
    }
}