#include <bits/stdc++.h>

using namespace std;

// # 1 map 풀이
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

// // # 2 배열 풀이
// int main() {
//     int N;
//     itn cnt[9];
//     int cur;
//     int max;

//     cin >> N;

//     fill(cnt, cnt + 9, 0);

//     if (N == 0) cnt[0]++;

//     while (N > 0) {
//         cur = N % 10;
//         if (cur == 9) {
//             cnt[6]++;
//         }
//         else {
//             cnt[cur]++;
//         }
//         N /= 10;
//     }

//     int temp = cnt[6] % 2;
//     cnt[6] /= 2;
//     cnt[6] += temp;

//     max = cnt[0];
//     for (int i = 1; i < 9; i++) {
//         if (max < cnt[i]) {
//             max = cnt[i];
//         }
//     }
//     cout << max << "\n";
//     return 0;
// }