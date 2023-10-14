/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res, diff = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int L = i + 1, R = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            while (L < R)
            {
                int tmpadd = nums[i] + nums[L] + nums[R];
                if (tmpadd == target)
                    return tmpadd;
                else if (tmpadd > target)
                {
                    if (diff > (tmpadd - target))
                    {
                        res = tmpadd;
                        diff = tmpadd - target;
                    }
                    R--;
                }
                else
                {
                    if (diff > (target - tmpadd))
                    {
                        res = tmpadd;
                        diff = target - tmpadd;
                    }
                    L++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
