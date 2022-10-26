#include <iostream>
#include <vector>
using namespace std;

void swap(int *n1, int *n2)
{
    int *temp = n1;
    n1 = n2;
    n2 = temp;
}

int gcd(int num1, int num2)
{
    while (num2 > 0)
    {
        if (num1 < num2)
            swap(num1, num2);
        num1 = num1 % num2;
        swap(num1, num2);
    }

    return num1;
}

int multiple_gcd(vector<int> arr)
{
    int n_gcd = -1;

    if (arr.size() == 1)
        return arr[0];
    n_gcd = gcd(arr[0], arr[1]);
    for (int i = 2; i < int(arr.size()); i++)
    {
        n_gcd = gcd(n_gcd, arr[i]);
    }
    return n_gcd;
}

void cases()
{
    int n, m, val, ret1, ret2;
    vector<int> arr, arr2;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }
    ret1 = multiple_gcd(arr);

    for (int i = 0; i < m; i++)
    {
        cin >> val;
        arr2.push_back(val);
    }
    ret2 = multiple_gcd(arr2);
    
    for (auto it : arr)
    {
        if (it % ret2 == 0)
            ret2 = -1;
    }

    for (auto it : arr2)
    {
        if (it % ret1 == 0)
            ret1 = -1;
    }
    cout << ret2 << " " << ret1 << "\n";
}

int main()
{
    int T;

    cin >> T;

    while (T--)
        cases();
}