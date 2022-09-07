// A + B
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases, n1, n2;
    cin >> cases;
    while (cases--)
    {
        cin >> n1 >> n2;
        cout << n1 + n2 << "\n";
    }
    return 0;
}