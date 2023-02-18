#include <bits/stdc++.h>

using namespace std;

void cases() {
    vector<int> vecs;
    map<int, int> maps;

    int N, nums;

    // cin >> N;

    for (int i = 0; i < 9; i++) {
        cin >> nums;
        // vecs.push_back(nums);
        maps.insert({nums, i + 1});
    }

    map<int, int>::iterator mi = prev(maps.end()); 

    cout << (*mi).first << "\n";
    cout << (*mi).second << "\n";
}

int main() {
    int T;
    T = 1;
    while (T--) {
        cases();
    }
}