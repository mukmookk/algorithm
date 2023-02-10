#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, sum;
    vector<int> vec;

    for (int i = 0; i < 9; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    for (auto i : vec) {
        cout << i << " ";
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            sum += vec[i];
            
        }
    }
}


// 1 2 3 4 5 20 25 30 35 40 