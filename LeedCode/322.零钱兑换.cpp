/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
// Force1 Force2 Memory DP1 DP2
#define DP2
#ifdef Force1
    int f(vector<int> &coins, int index, int amount)
    {
        if (index == coins.size())
            return amount == 0 ? 0 : -1;
        if (amount == 0)
            return 0;
        int res = -1;
        for (int i = 0; amount - i * coins[index] >= 0; ++i)
        {
            int next = f(coins, index + 1, amount - i * coins[index]);
            if (next != -1)
                res = (res == -1 ? next + i : min(res, i + next));
        }
        return res;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        return f(coins, 0, amount);
    }
#endif

#ifdef Force2
    int coinChangeRecursive(std::vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = coinChangeRecursive(coins, amount - coin);
            if (subproblem != -1)
                minCoins = std::min(minCoins, subproblem + 1);
        }
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int coinChange(std::vector<int> &coins, int amount)
    {
        return coinChangeRecursive(coins, amount);
    }
#endif

#ifdef Memory
    int coinChangeRecursive(std::vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount < 0)
            return -1;
        if (dp[amount] != -2)
            return dp[amount];

        if (amount == 0)
        {
            dp[amount] = 0;
            return dp[amount];
        }

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = coinChangeRecursive(coins, amount - coin, dp);
            if (subproblem != -1)
                minCoins = std::min(minCoins, subproblem + 1);
        }
        dp[amount] = minCoins == INT_MAX ? -1 : minCoins;
        return dp[amount];
    }

    int coinChange(std::vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -2);
        return coinChangeRecursive(coins, amount, dp);
    }
#endif

#ifdef DP1
    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int row = coins.size() + 1, col = amount + 1;
        for (int i = 0; i < row; i++)
            dp[i][0] = 0;
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = col - 1; j > 0; --j)
            {
                for (int num = j / coins[i]; num >= 0; --num)
                {
                    int next = dp[i + 1][j - num * coins[i]];
                    if (next != -1)
                        dp[i][j] = dp[i][j] == -1 ? next + num : min(dp[i][j], num + next);
                }
            }
        }
        return dp[0][amount];
    }
#endif

#ifdef DP2
    int coinChangeRecursive(std::vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int minCoins = INT_MAX;
        for (int coin : coins)
        {
            int subproblem = coinChangeRecursive(coins, amount - coin);
            if (subproblem != -1) // 之前的状态可以被凑成
                minCoins = std::min(minCoins, subproblem + 1);
        }
        return minCoins == INT_MAX ? -1 : minCoins;
    }

    int coinChange(std::vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (const auto &coin : coins)
            {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
#endif
};
// @lc code=end
