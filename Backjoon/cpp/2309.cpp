#include <bits/stdc++.h>

using namespace std;

int main() {
    int num, total;
    vector<int> vec;
    int res[7];

    for (int i = 0; i < 9; i++) {
        cin >> num;
        vec.push_back(num);
    }

    // n1, n2: 배제할 난쟁이 번호
    // 모든 조합을 찾아서 brute force
    for (int n1 = 0; n1 < 8; n1++) {
        for (int n2 = n1 + 1; n2 < 9; n2++) {
            total = 0;
            // 0 ~ 9까지의 난쟁이를 추가할 수 있지만, 그 중 n1과 n2를 제외하고 res에 저장
            for (int num = 0, i = 0; num < 9; num++) {
                if (num != n1 && num != n2) {
                    res[i++] = vec[num];    // i는 res가 기록될 때마다 증가
                }
            }

            // 총 합 구하고
            for (int i = 0; i < 7; i++) {
                total += res[i];
            }
            // 총 합이 100이라면 탈출
            if (total == 100)
                break;
        }
        // 이어서 그 다음 루프도 탈출시켜주며 마무리
        if (total == 100)
            break;
    }

    sort(res, res + 7);

    for (int i = 0; i < 7; i++) 
        cout << res[i] << "\n";
}
