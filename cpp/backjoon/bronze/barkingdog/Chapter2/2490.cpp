#include <bits/stdc++.h>

using namespace std;

void compute(vector<int> &vec) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (vec[i] == 0) {
            count = count + 1;
        }
    }

    switch (count) {
        case 1:
            cout << "A";
            break;
        case 2:
            cout << "B";
            break;
        case 3:
            cout << "C";
            break;
        case 4:
            cout << "D";
            break;
        case 0:
            cout << "E";
            break;
    }
    cout << "\n";
    vec.clear();
}

int main() {
    int N, num;

    N = 3;
    vector<int> vec;

    for (int i = 0; i < 4 * N; i++) {
        cin >> num;
        vec.push_back(num);

        if (vec.size() == 4)
            compute(vec);
    }
}