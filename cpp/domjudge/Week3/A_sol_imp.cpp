#include <iostream>
#include <vector>

using namespace std;
int CalcMedian()
{
    int med = 0, med_count = 0, c = -1;

    if (d % 2 == 1)
    {
        for (int i = 0; i < 200; i++)
        {
            med_count = med_count + CntArray[i];
            if (med_count > d / 2)
            {
                med = CntArray[i] * 2;
            }
        }
    }
    else if (d % 2 == 0)
    {
        for (int i = 0; i < 200; i++)
        {
            med_count = med_count + CntArray[i];
            if (med_count > d / 2)
            {  
                med = CntArray[i-1] + ;
                med += CntArray[i];
            }
        }        
    }
    return 0;
}

int main()
{
    int n, d, val;   // 입력값
    int count, median;

    cin >> n >> d;
    int calorie[n + 1], CntArray[201];

    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        calorie[i] = val;
    }
    
    for (int i = 0; i <= 200; i++)
        CntArray[i] = 0;

    for (int i = 1; i <= d; i++)
    {
        CntArray[calorie[i]]++;
    }
    for (int i = d + 1; i <= n; i++)
    {
        median = CalcMedian();
        if median <= calorie[i]
        {
            count++;
        }
        CntArray[calorie[i - d]]--;
        CntArray[calorie[i]]++;
    }
    for (auto val : CntArray)
        cout << val << " ";
    cout << "\n";
}