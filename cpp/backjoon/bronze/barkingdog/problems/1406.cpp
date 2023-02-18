#include <bits/stdc++.h>

using namespace std;

int main() {
    string baseline;
    int M;

    cin >> baseline;
    cin >> M;
    list<string> L;
    for (auto it : baseline) {
        L.push_back(string(1, it));
    }

    list<string>::iterator it = L.end();

    while (M--) {
        string inst;
        cin >> inst;
        if (inst == "P") {
            string ch;
            cin >> ch;
            L.insert(it, ch);
        }
        else if (inst == "L") {
            if (it != L.begin()) { it--; }
        }
        else if (inst == "D") {
            if (it != L.end()) { it++; }
        }
        else if (inst == "B") {                
            if (!L.empty() && it != L.begin()) { 
                list<string>::iterator t = L.erase(prev(it)); 
                it = t; 
                }
        }
    }

    for (auto item : L) {
        cout << item;
    }
}