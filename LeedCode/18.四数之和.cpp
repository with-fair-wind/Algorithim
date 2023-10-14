/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (nums.size() < 4)
            return {};
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int L = j + 1, R = nums.size() - 1;
                while (L < R)
                {
                    long long tmpadd = (long long)nums[i] + (long long)nums[j] + (long long)nums[L] + (long long)nums[R];
                    if (tmpadd == target)
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[L], nums[R]});
                        while (L < R && nums[L + 1] == nums[L])
                            L++;
                        while (L < R && nums[R - 1] == nums[R])
                            R--;
                        L++;
                        R--;
                    }
                    else if (tmpadd < target)
                    {
                        while (L < R && nums[L + 1] == nums[L])
                            L++;
                        L++;
                    }
                    else
                    {
                        while (L < R && nums[R - 1] == nums[R])
                            R--;
                        R--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
