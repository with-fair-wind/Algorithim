// @before-stub-for-debug-begin
#include "commoncppproblem121.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX, maxProfit = 0;
        for (const int &cur : prices)
        {
            maxProfit = max(maxProfit, cur - minPrice);
            minPrice = min(minPrice, cur);
        }
        return maxProfit;
    }

    int process(vector<int> &prices, int index)
    {
        if (index == prices.size() - 1)
            return 0;
        int maxprofit = 0, buy = prices[index];
        for (int i = index + 1; i < prices.size(); i++)
            if (prices[i] > buy)
                maxprofit = prices[i] - buy > maxprofit ? prices[i] - buy : maxprofit;
        return max(maxprofit, process(prices, index + 1));
    }

    int ans2(vector<int> &prices)
    {
        vector<int> arr(prices.size());
        arr[prices.size() - 1] = 0;
        for (int index = prices.size() - 2; index >= 0; index--)
        {
            int maxprofit = 0, buy = prices[index];
            for (int i = index + 1; i < prices.size(); i++)
                if (prices[i] > buy)
                    maxprofit = prices[i] - buy > maxprofit ? prices[i] - buy : maxprofit;
            arr[index] = max(maxprofit, arr[index + 1]);
        }
        return arr[0];
    }
};
// @lc code=end
