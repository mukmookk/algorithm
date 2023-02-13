#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> num;

int main() {
    string input;

    cin >> input;

    for (size_t i = 0; i < 9; i++) {
        num.insert({input[i], 0});
    }

    for (size_t i = 0; i < input.size(); i++) {
        int val = stoi(input.substr(i, 1));
        if (val == 9) { val = 6;} 
        num[val]++;
    }
    int temp = num[6] % 2;
    num[6] /= 2;
    num[6] += temp;
    
    auto pr = max_element(num.begin(), num.end(), [](const auto &x, const auto &y)
    {
        return x.second < y.second;
    });
    
    
    cout << pr->second << "\n";
}