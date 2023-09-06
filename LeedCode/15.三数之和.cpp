// @before-stub-for-debug-begin
#include "commoncppproblem15.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                return res;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int L = i + 1, R = nums.size() - 1;
            while (L < R)
            {
                int tmpadd = nums[i] + nums[L] + nums[R];
                if (!tmpadd)
                {
                    res.push_back({nums[i], nums[L], nums[R]});
                    while (L < R && nums[L + 1] == nums[L])
                        L++;
                    while (L < R && nums[R] == nums[R - 1])
                        R--;
                    L++;
                    R--;
                }
                else if (tmpadd > 0)
                    R--;
                else
                    L++;
            }
        }
        return res;
    }
};
// @lc code=end
