void main()
{
    int n, d;
    int count, median; // median 에는 중앙값 * 2 값을 넣어주게 된다.
    int calorie[1..n], CntArray[0...200] // -> O(n+k)

    read n, d;
    // O(n)
    for i = 1 to n
        read calorie[1..n]
    // O(n)
    for i = 1 to d
        CntArray[calorie[i]]++
    // O(kn)
    for i = d+1 to n
        median = CalcMedian() // -> O(k)
        if median <= calorie[i]
            count++
        CntArray[calorie[i-d]]--
        CntArray[calorie[i]]++
}

void CalcMedian()
{
    int med_count = 0, c = -1

    // 홀수 짝수 (각각 O(n))
    if d % 2 == 1
        for i = 0 to 200
            med_count = med_count + CntArray[i];
            if med_count > d / 2
                med = med * 2
                break
    // 짝수
    else
        위와 동일 다만, 이제 같은 값에 대해서 count를 참조하는 경우 문제가 될 수 있음
        그래서 왼쪽 값을 변경하면 C를 갱신하게 하여 해당 값과 오른쪽 값을 의미하는 i를 더해서 return 해준다.


}

[2 3 5 5 3 4] 1

0 2 2 0 1 1