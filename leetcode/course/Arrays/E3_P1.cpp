#include <set>
#include <iostream>
#include <vector>

using namespace std;

int maxDifference(vector<int> &nums)
{
    multiset<int> maxima;
    auto max_iter = max_element(nums.begin(), nums.end());
    for (auto it = nums.begin(); it != prev(nums.end()); it++)
    {
        auto local_max = max_element(next(it), nums.end());
        maxima.insert(*local_max - *it);
    }
    return *prev(maxima.end());
}

int main()
{
    int n, val;
    vector<int> vec;

    cin >> n;
    while (n--)
    {
        cin >> val;
        vec.push_back(val);
    }
    cout << maxDifference(vec) << "\n";
}