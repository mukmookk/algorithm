#include <iostream>
#include <vector>

using namespace std;

void swap (int *num1, int *num2) {
    int *temp;

    temp = num1;
    num1 = num2;
    num2 = temp;
}

int gcd(int num1, int num2) {
    while (num2 > 0) {
        if (num2 > num1)
            swap(num1, num2);
        num1 = num1 % num2;
        swap(num1, num2);
    }
    return num1;
}

int multiple_gcd(vector<int> vals) {
    int n_gcd = -1;

    if (vals.size() == 0)
        return vals[0];
    n_gcd = gcd(vals[0], vals[1]);
    for (int i = 2; i < vals.size(); i++) {
        n_gcd = gcd(n_gcd, vals[i]);
    }
    return n_gcd;
}

void cases() {
    int M, N, val, ret1, ret2;
    vector<int> arr, arr2;

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> val;
        arr.push_back(val);
    }
    ret1 = multiple_gcd(arr);

    for (int i = 0; i < N; i++) {
        cin >> val;
        arr2.push_back(val);
    }
    ret2 = multiple_gcd(arr2);

    for (auto it : arr) {
        if (it % ret2 == 0) {
            ret2 = -1;
        }
    }

    for (auto it : arr2) {
        if (it % ret1 == 0) {
            ret1 = -1;
        }
    }
    cout << ret2 << " " << ret1 << "\n";

}

int main() {
    int T;

    cin >> T;

    while (T--) {
        cases();
    }
}