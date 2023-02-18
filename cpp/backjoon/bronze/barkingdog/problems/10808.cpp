#include <bits/stdc++.h>

using namespace std;

int alpha[127];

int main() {

    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        alpha[word[i]]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alpha['a' + i] << " ";
    }
}