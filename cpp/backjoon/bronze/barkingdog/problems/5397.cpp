#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    cin >> N;
    while (N--) {
        list<char> L;
        string input;

        cin >> input;
        auto it = L.begin();
        
        for (auto item : input) {
            if (item == '<') {
                if (it != L.begin()) { it = prev(it); }
            }
            else if (item == '>') {
                if (it != L.end()) { it = next(it); }
            }
            else if (item == '-') {
                if (it != L.begin()) {
                    auto t = L.erase(prev(it));
                    it = t;
                }
            }
            else {
                L.insert(it, item);
            }

        }

        for (auto item : L) {
            cout << item;
        }
        cout << "\n";
    }
}

