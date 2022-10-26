#include <vector>
#include <string>
#include <set>
#include <iostream>

#define NO "NO"
#define YES "YES"

using namespace std;
void cases() {
    string str, ret;

    set<int> s_str1, s_str2;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        s_str1.insert(str[i]);
    }

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        s_str2.insert(str[i]);
    }
    
    if (s_str1.size() != s_str2.size())
        ret = NO;
    else 
    {
        ret = YES;
        for (auto it = s_str1.begin(), it2 = s_str2.begin(); it != s_str1.end(); it++, it2++) {
            if (*it != *it2)
                ret = NO;
        }
    }

    cout << ret << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}