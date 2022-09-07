// 합
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, output;

    output = 0;
    cin >> n;
    while (n > 0)
        output = output + n--;
    cout << output;
}