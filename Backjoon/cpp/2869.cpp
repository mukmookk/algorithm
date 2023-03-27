#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, V, pos, day;
    cin >> A >> B >> V;

    pos = day = 0;
    
    // 점화식을 활용하여 해결
    // 밤은 계산하지 않으며, 낮을 체크하는 게 포인트
    // Naive 하게 접근하면 시간 초과
    /*
    day 1 dayooday: A
    day 1 dayight: A - B
    day 2 dayooday: A - B + A
    day 2 dayight: A - B + A - B
    ...
    day N Night: V = A * day - B * (day - 1)

    달팽이가 V라는 목표에 도달한 상황을 가정하고 식을 정리
    V = A * day - B * day + B
    day (A - B) = B + V
    day = (V - B) / (A - B), 문제의 조건으로부터 A != B 확인 가능
    */
    3 / 2 = 1
    3 * 1.0 / 2 = 1.5
    
    day = ceil((V - B) * 1.0 / (A - B));
    cout << day;

    // cout << "\n" << ceil((1 - 0) * 1.0/ (3 - 0));
}

// 2  5
// 2 1 3 