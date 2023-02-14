#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        // 꼭 초기화를 해주자, 예상치 못한 동작이 발생할 수 있다.
        int alphas[127] = {0, };
        string src, dest;

        cin >> src >> dest;

        // 길이가 달라도 가능하다. (앞의 문자가 뒤의 문자를 만들 수 있다면)
        // No -> strfry라는 조건에 따라 길이가 같아야 함...
        if (src.size() != dest.size()) {
            cout << "Impossible" << "\n";
            continue;
        }

        for (int j = 0; j < src.size(); j++) {
            alphas[src[j]]++;
        }

        int count = 0;
        for (int j = 0; j < dest.size(); j++) {
            if (alphas[dest[j]] == 0) {
                cout << "Impossible" << "\n";
                break;
            }
            count++;
            alphas[dest[j]]--;
        }
        if (count == dest.size()) { cout << "Possible" << "\n"; }
    }
}