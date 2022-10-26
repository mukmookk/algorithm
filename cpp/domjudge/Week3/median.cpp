#include <iostream>
#include <vector>

using namespace std;
double findMedian(vector<int> a, int n)
{
    // If size of the arr[] is even
    if (n % 2 == 0)
    {
        // Applying nth_element
        // on n/2th element
        nth_element(a.begin(), a.begin() + n / 2, a.end());
        nth_element(a.begin(), a.begin() + (n - 1) / 2, a.end());
        
        // Find the average of value at index N/2 and (N-1)/2
        return (double) (a[n - 1] / 2 + a[n-1]) / 2.0;
    }
    // if size of the arr[] is odd
    else
    {
        // Applying nth_element
        // on n/2
        nth_element(a.begin(), a.begin() + n / 2, a.end());
        return double(a[n / 2]);
    }
}