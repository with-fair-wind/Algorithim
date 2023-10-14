/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int dfs(const vector<int> &nums1, int index1, const vector<int> &nums2, int index2, int length)
    {
        if (index1 == nums1.size() || index2 == nums2.size())
            return length;
        int len1, len2, len3;
        if (nums1[index1] == nums2[index2])
            len1 = dfs(nums1, index1 + 1, nums2, index2 + 1, length + 1);
        else
            len1 = length;

        len2 = dfs(nums1, index1 + 1, nums2, index2, 0);
        len3 = dfs(nums1, index1, nums2, index2 + 1, 0);

        return max(len1, max(len2, len3));
    }

    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // return dfs(nums1, 0, nums2, 0, 0);
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLength = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, dp[i][j]);
                }
            }
        }

        return maxLength;
    }
};
// @lc code=end
