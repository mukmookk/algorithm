#include <iostream>
#include <map>
#include <vector>

using namespace std;

void cases() {
    int N, K, val, price, cnt;

    vector<int> W1, W2;
    multimap<int, int> m;

    cnt = 0;
    cin >> N >> K;
    for (int i = 0; i  < N; i++) {
        cin >> val;
        W1.push_back(val);
    }

    for (int i = 0; i  < N; i++) {
        cin >> val;
        W2.push_back(val);
    } 

    for (int i = 0; i < N; i++) {
        m.insert(make_pair(W2[i] / W1[i], W2[i]));
    }

    price = 0;
    for (auto it = m.rbegin(); it != m.rend() && K > 0; it++) {
        if (K - it->second / it->first < 0) { 
            K = 0;
            cnt += K * it->first;
        }
        else {
            K -= it->second / it->first;
            cnt += it->second;
        }
    }
    cout << cnt << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}