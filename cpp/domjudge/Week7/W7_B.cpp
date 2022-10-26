#include <bits/stdc++.h>
using namespace std;
void cases() {
    string str;
    int length;
    cin >> str;
    stack<int> stk;
    string::iterator it;
    
    length = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            //if (str.size() - i < stk.size())
            //    break ;

            if (stk.empty())
                stk.push(str[j]);
            else if (str[j] == stk.top())
                stk.push(str[j]);
            else {
                stk.pop();
                if (stk.empty()) {
                    length = max(j - i + 1, length);
                }
                if (stk.size() > str.size() - j)
                    break;
            }
        }
        stk = stack<int>{};
    }
    cout << length << "\n";
}

int main() {
    int T;

    cin >> T;
    while(T--)
    {
        cases();
    }
}