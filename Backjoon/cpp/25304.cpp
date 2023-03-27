#include <iostream>
#include <string>
using namespace std;

const string YES = "Yes";
const string NO = "No";

int calculator() 
{
    int total, items, item, q;

    total = 0;
    cin >> total >> items;
    while (items-- && cin >> item >> q)
        total -= (item * q);
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << (calculator() == 0 ? YES : NO) << "\n";
}