/**
 * @brief You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
 * 
 */
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int current_diff = 0;
        int profit = 0;
        
        prices.push_back(0);
        for (int i = 1; i < prices.size(); i++)
        {
            min_val = min(min_val, prices[i]);
            if (prices[i] < prices[i-1])
            {
                profit += current_diff;
                min_val = prices[i];
                current_diff = 0;
            }
            else
                current_diff = max(current_diff, prices[i] - min_val);
        }
        return profit;
    }
};