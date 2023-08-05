// @before-stub-for-debug-begin
#include "commoncppproblem746.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
#if 0
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(process(cost, 0, 0), process(cost, 0, 1));
    }

    int process(vector<int> &cost, int money, int index)
    {
        if (index >= cost.size())
            return money;
        return min(process(cost, money + cost[index], index + 1), process(cost, money + cost[index], index + 2));
    }
#else
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.size(); ++i)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }
#endif
};
// @lc code=end
