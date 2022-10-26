#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void cases() {
    long long digits;
    int count = 0, length = 0;
    string m;

    int digit, n_digit;

    cin >> m;
    length = m.size();

    for (int i = length - 1; i >= 0; i--) {
        digit = m[i] -'0';
        n_digit = m[i + 1] - '0';
        if (digit >= 6 || (digit >= 5 && n_digit >= 5)) {
            digits = stoul(m) + (10  - digit) * pow(10, length - 1 - i);
            count += (10 - digit);
            m = to_string(digits);
            if (m.size() > length) {
                count = count + 1;
                break;
            }
        }
        else {
            digits = stoul(m) - digit * pow(10, length - 1 + i);
            count += digit;
        }
    }
    cout << count << "\n";
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cases();
    }
}