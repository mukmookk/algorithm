#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

// 현재 자리 수가 5 이상 다음 자리 수가 5인 경우, 올리는 경우가 낫다.
// 그 다음 자리까지 고려했을때, 횟수 상의 이득을 볼 수 없을지도 모르지만 이득 볼 수도 있다. 최소 손해는 안본다.
// 마지막에는 min(vec[i], 10 - vec[i] + 1) 로 둘 중 하나를 고를 수 있도록
// 10^10보다 크게 해서 완전 탐색을 막을려다가 그냥 놔뒀다고 한다.

// 자릿수에 따라 연산이 이뤄지므로 log n 만큼의 사간복잡도가 필요하다.

using namespace std;

void greedyConsumption()
{
    long long length, digit, n_digit, digits, count;
    string s;

    cin >> s;
    count = 0;
    length = s.length();
    //reverse(s.begin(), s.end());
    for (int i = length - 1; i >= 0; i--)
    {
        digit = s[i] - '0';
        n_digit = s[i - 1] - '0';
        if (digit >= 6 || (digit == 5 && n_digit >= 5))
        {
            digits = stoull(s) + (10 - digit) * pow(10, length - i - 1);
            count += (10 - digit);
            s = to_string(digits);
            if ((int)length < (int)s.length())
            {
                count = count + 1;
                break;
            }
        }
        else
        {
            digits = stoull(s) - digit * pow(10, length - i - 1);
            count += digit;
            s = to_string(digits);  
        }
    }
    cout << count << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        greedyConsumption();
}

