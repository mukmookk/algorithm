#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

void cases()
{
    int start, end, count, max_map, last_T;

    string str;
    start = end = max_map = count = 0;
    
    cin >> str;

    int arr_length = str.size();
    int arr[arr_length];
    for (int i = 0; i < arr_length; i++) {
        if (str[i] == 'C')
            arr[i] = 1;
        else
            arr[i] = -1;
    }

    count = 0;
    for (int i = 0; i < arr_length; i++)
    {
        count += arr[i];
        cout << arr[i] << " " << count << " " << end << " - " << start << "\n";
        if (count < 0) {
            end = i;
            last_T = i;
            max_map = max(max_map, end - start);
            count = 0;
            start = i + 1;
        }
  
    }

    cout << max_map << endl;
}

int main()
{
    int T;
    
    cin >> T;

    while (T--)
    {
        cases();
    }
}