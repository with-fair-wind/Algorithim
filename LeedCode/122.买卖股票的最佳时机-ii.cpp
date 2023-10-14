/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
// Force Memory DP
#define DP
#ifdef Force
    int f(vector<int> &prices, int index, int status)
    {
        if (index == prices.size())
            return 0;
        int tmp1, tmp2;
        if (status == 0)
        {
            tmp1 = f(prices, index + 1, 0);
            tmp2 = f(prices, index + 1, 1) - prices[index];
        }
        else
        {
            tmp1 = f(prices, index + 1, 0) + prices[index];
            tmp2 = f(prices, index + 1, 1);
        }
        return tmp1 < tmp2 ? tmp2 : tmp1;
    }

    int maxProfit(vector<int> &prices)
    {
        return f(prices, 0, 0);
    }
#endif
#ifdef Memory
    int f(vector<int> &prices, int index, int status, vector<vector<int>> &dp)
    {
        if (dp[index][status] != -1)
            return dp[index][status];
        if (index == prices.size())
        {
            dp[index][status] = 0;
            return dp[index][status];
        }
        int tmp1, tmp2;
        if (status == 0)
        {
            tmp1 = f(prices, index + 1, 0, dp);
            tmp2 = f(prices, index + 1, 1, dp) - prices[index];
        }
        else
        {
            tmp1 = f(prices, index + 1, 0, dp) + prices[index];
            tmp2 = f(prices, index + 1, 1, dp);
        }
        dp[index][status] = tmp1 < tmp2 ? tmp2 : tmp1;
        return dp[index][status];
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return f(prices, 0, 0, dp);
    }
#endif
#ifdef DP
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;
        for (int row = prices.size() - 1; row >= 0; row--)
        {
            dp[row][0] = max(dp[row + 1][0], dp[row + 1][1] - prices[row]);
            dp[row][1] = max(dp[row + 1][0] + prices[row], dp[row + 1][1]);
        }
        return dp[0][0];
    }
#endif
};
// @lc code=end
