#include <vector>
#include <iostream>

using namespace std;
void swap (int *num1, int *num2) {
    int *temp = num1;
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

int multiple_gcd(vector<int> arr) {
    int res = -1;

    if (arr.size() == 1)
        return arr[0];
    res = gcd(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        res = gcd(res, arr[i]);
    }
    return res;
}

void cases() {
    int n, m, val, res1, res2;
    vector<int> arr1, arr2;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val;
        arr1.push_back(val);
    }

    for (int i = 0; i < m; i++) {
        cin >> val;
        arr2.push_back(val);
    }

    res1 = multiple_gcd(arr1);
    res2 = multiple_gcd(arr2);

    for (int i = 0; i < m; i++) {
        if (arr1[i] % res2 == 0) {
            res2 = -1;
        }
    }

    //for (int i = 0; i < n; i++) {
    //    if (arr2[i] % res1 == 0) {
    //        res1 = -1;
    //    }
    //}
    //for (auto it : arr1)
    //{
    //    if (it % res2 == 0)
    //        res2 = -1;
    //}

    //for (auto it : arr2)
    //{
    //    if (it % res1 == 0)
    //        res1 = -1;
    //}
    //cout << res2 << " " << res1 << "\n";
    cout << res2 << " " << res1 << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}