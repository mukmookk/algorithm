// A 식단 관리
/*
** 중앙값: 정렬되었을 때 가운데 값
** 
** 고려해야할 특징: 
** 1. 섭취량의 숫자 크가 특정한 범위에 존재
** 2. d일 동안의 고객의 섭취량의 중앙값을 구하기 위해 빠른 속도의 정렬이 필요
** 3. 원소의 개수가 짝수인지 홀수인지에 대해서 유의
*/

/*
알고리즘 설명
정렬을 다른 관점에서 살펴보자. 지금까지는 정렬을 하는 입장에서만, 오름차순, 내림차순을 할 뿐이였다 (유치원 선생님). 
유치원 학생이라고 생각하자. 정렬을 당하는 입장에선 내 앞에 모두 크거나, 혹은 내 앞이 모두 작은 학생만 존재한다.

0-based index: 내 앞에 원소가 몇개 있는지
1-based index: 내가 몇 번째 원소인지(=rank)
유치원 생의 입장이라면, 내가 몇 번째로 키가 큰지 라고 할 수 있다.

이전 d일 동안의 고객의 섭취량
{[2, 3, 4, 2, 3], 6, 8, 4, 5}, d = 5

섭취량 count 표
{0, 2, 2, 1, 0, 0, 0, 0, 0} -> 3번째 원소를 찾으면 된다, 3번째 원소

n이 홀수일 경우 n / 2는 내림이 되기 때문에 1을 더해서 1-based index를 활용할 수 있도록 한다.

이때, window를 갱신하며 섭취량 count 표를 변경할 경우, 맨 앞에 위치했던 값에 대한 count를 하나 감소시켜주고, 새롭게 추가된  값에 대해서 count를 1 추가해준다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> medianSlidingWindow(vector<int> &nums, int k)
{
    vector<double> medians;

    for (int i = 0; i + k <= nums.size(); i++)
    {
        vector<int> window(nums.begin() + i, nums.begin() + i + k);

        sort(window.begin(), window.end());

        if (k & 1)
            medians.push_back(window[k / 2]);
        else
            medians.push_back((window[k/2] + window[k/2 -1]) / 2.0);
    }
    return medians;
}

void diet_alert()
{
    int n, d, cal, count;

    vector<int> calories;
    vector<double> medians;
    cin >> n >> d;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cal;
        calories.push_back(cal);
    }
    medians = medianSlidingWindow(calories, d);
    for (int i = 0; i + d < n; i++)
    {        
        if (calories[i + d] >= 2 * medians[i])
        {
            count = count + 1;
        }
    }
    cout << count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //// Total T cases
    int T = 0;
    cin >> T;
    while (T--)
    {
        diet_alert();
        cout << "\n";
    }
    return 0;
}