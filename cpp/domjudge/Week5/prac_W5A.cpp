#include <iostream>
#include <string>
#include <set>

#define NO "NO"
#define YES "YES"

using namespace std;

string emp_detector() {
    string original, target;
    set<char> s_src, s_tar;

    cin >> original >> target;

    for (int i = 0; i < original.size(); i++) {
        s_src.insert(original[i]);
    }

    for (int i = 0; i < target.size(); i++) {
        s_tar.insert(target[i]);
    }

    if (s_src.size() != s_tar.size())
        return NO;
    
    for (auto it = s_src.begin(), it2 = s_tar.begin(); it != s_src.end(); it++, it2++) {
        if (*it != *it2)
            return NO;
    }
    return YES;
}

int main() {
    int T;

    cin >> T;
    while (T--)
        cout << emp_detector() << "\n";
}