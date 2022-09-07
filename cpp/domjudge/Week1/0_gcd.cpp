#include <iostream>

using namespace std;

void swap(int *num1, int *num2)
{
    int *temp;

    temp = num1;
    num1 = num2;
    num2 = temp;
}

int gcd(long long num1, long long num2)
{
    while (num2 > 0)
    {
        if (num2 > num1)
            swap(num1, num2);
        num1 = num1 % num2;
        swap(num1, num2);
    }
    return num1;
}

long long lcm(long long num1, long long num2, long long gcd)
{
    return num1 * num2 / gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long num1, num2, n_gcd, n_lcm;
    cin >> num1 >> num2;
    
    n_gcd = gcd(num1, num2);
    n_lcm = lcm(num1, num2, n_gcd);
    cout << n_gcd << "\n" << n_lcm << "\n";
    return 0;
}