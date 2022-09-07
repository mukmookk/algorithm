/**
Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

()
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int current_diff = 0;
        
        for (int idx = 1; idx < prices.size(); idx++)
        {
            min_val = min(min_val, prices[idx]);
            current_diff = max(current_diff, prices[idx] - min_val);
        }
        return current_diff;
    }
};