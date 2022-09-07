// 구구단 
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i;

    cin >> n;
    i = 0;
    while (++i < 10)
        cout << n << " * " << i << " = " << n * i << "\n";
}