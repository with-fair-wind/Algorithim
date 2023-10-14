/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
#if 1
    int dfs(string text1, int index1, string text2, int index2, string path)
    {
        if (index1 == text1.length() || index2 == text2.length())
            return path.size();

        if (text1[index1] == text2[index2])
        {
            path.push_back(text1[index1]);
            return dfs(text1, index1 + 1, text2, index2 + 1, path);
        }
        else
        {
            int tmp1 = dfs(text1, index1 + 1, text2, index2, path);
            int tmp2 = dfs(text1, index1, text2, index2 + 1, path);

            return max(tmp1, tmp2);
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        string path;
        return dfs(text1, 0, text2, 0, path);
    }

#else
#if 0
    int dfs(string text1, int index1, string text2, int index2, vector<vector<int>> &dp)
    {
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (index1 == text1.length() || index2 == text2.length())
        {
            dp[index1][index2] = 0;
            return dp[index1][index2];
        }

        if (text1[index1] == text2[index2])
        {
            dp[index1][index2] = 1 + dfs(text1, index1 + 1, text2, index2 + 1, dp);
            return dp[index1][index2];
        }
        else
        {
            int tmp1 = dfs(text1, index1 + 1, text2, index2, dp);
            int tmp2 = dfs(text1, index1, text2, index2 + 1, dp);
            dp[index1][index2] = max(tmp1, tmp2);
            return dp[index1][index2];
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        return dfs(text1, 0, text2, 0, dp);
    }
#else
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1));
        for (int row = text1.length() - 1; row >= 0; --row)
        {
            for (int col = text2.length() - 1; col >= 0; --col)
            {
                if (text1[row] == text2[col])
                {
                    dp[row][col] = 1 + dp[row + 1][col + 1];
                }
                else
                {
                    dp[row][col] = max(dp[row + 1][col], dp[row][col + 1]);
                }
            }
        }

        return dp[0][0];
    }
#endif
#endif
};
// @lc code=end
