// @before-stub-for-debug-begin
#include "commoncppproblem31.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int R = nums.size() - 1, L = R - 1;
        while (L >= 0 && nums[L] >= nums[L + 1]) // 从L + 1 到end都是递减的
            L--;
        if (L >= 0)
        {
            while (nums[R] <= nums[L])
                R--;
            swap(nums[L], nums[R]);
            reverse(nums.begin() + L + 1, nums.end());
        }
        else
            reverse(nums.begin(), nums.end());
    }
};
// @lc code=end
