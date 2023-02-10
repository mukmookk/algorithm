#include <bits/stdc++.h>

using namespace std;

int implement(){
    map<int, int> m;
    int ret = 0;
    int one_pos;

    for (int i = 1; i <= 6; i++)
        m.insert({i, 0});
    
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    for (int i = 1; i <= 6; i++) {
        if (m[i] == 3) {
            ret = 10000 + i * 1000;
            return ret;
        }
        else if (m[i] == 2) {
            ret = 1000 + i * 100;
            return ret;
        }
        else if (m[i] == 1) {
            one_pos = i;
        }
    }

    return one_pos * 100;
}

int main()
{
    cout << implement();
}