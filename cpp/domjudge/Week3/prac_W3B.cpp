#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void greedyConsumption() {
    long long digits;
    int count, digit, n_digit, length;
    string s;

    cin >> s;
    count = 0;
    length = s.length();

    for (int i = length - 1; i >= 0; i--) {
        digit = s[i] - '0';
        n_digit = s[i - 1] - '0';
        if (digit >= 6 || (digit == 5 && n_digit >= 5)) {
            digits = stoul(s) + (10 - digit) * pow(10, (length - 1) - i);
            count += (10 - digit);
            s = to_string(digits);
            if ((int)length < (int)s.length()) {
                count = count + 1;
                break;
            }
        }
        else {
            digits = stoul(s) - digit * pow(10, (length - 1) - i);
            count += digit;
            s = to_string(digits);
        }
    }
    cout << count << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        greedyConsumption();
    }
}