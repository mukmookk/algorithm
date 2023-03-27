#include <bits/stdc++.h>

using namespace std;

int s_alphas[127] = {0,};
int d_alphas[127] = {0, };

int main() {
    // 접근 방법: 두 단어의 알파벳을 카운트 후 둘을 비교, 
    // 만약 한 쪽에 있고 다른 쪽엔 없다면 빼주고 뺀 만큼 res에 추가

    string src, dest;
    int total;
    cin >> src >> dest;

    for (int i = 0; i < src.size(); i++) { s_alphas[src[i]]++; }
    for (int i = 0; i < dest.size(); i++) { d_alphas[dest[i]]++; }

    total = 0;
    for (int i = int('a'); i <= int('z'); i++) {
        int val = s_alphas[i];
        val -= d_alphas[i];

        val = abs(val);
        total += val;
    }
    cout << total << "\n";
}