#include <map>
#include <vector>
#include <iostream>

using namespace std;

void getMaximumPurchase() {
    int N, K, input, ans;
    multimap<int, int> products;
    vector<int> vec1, vec2;

    ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> input;
        vec1.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        cin >> input;
        vec2.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        products.insert(make_pair(vec2[i] / vec1[i], vec2[i]));
    }

    for (auto it = products.rbegin(); it != products.rend() && K > 0; it++) {
        if (K - it->second / it->first < 0) {
            ans += K * it->first;
            K = 0;
        }
        else {
            ans += it->second;
            K -= it->second / it->first;
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--)
        getMaximumPurchase();
}