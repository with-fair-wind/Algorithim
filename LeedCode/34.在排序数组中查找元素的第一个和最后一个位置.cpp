// @before-stub-for-debug-begin
#include "commoncppproblem34.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> f(vector<int> &nums, int L, int R, int target)
    {
        if (L > R)
            return {-1, -1};
        if (L == R)
            return nums[L] == target ? vector<int>{L, L} : vector<int>{-1, -1};
        int mid = L + ((R - L) >> 1);

        if (nums[mid] < target)
            return f(nums, mid + 1, R, target);
        else if (nums[mid] > target)
            return f(nums, L, mid - 1, target);
        else
        {
            vector<int> leftinfo = f(nums, L, mid - 1, target);
            vector<int> rightinfo = f(nums, mid + 1, R, target);
            int leftbound = leftinfo[0] == -1 ? mid : leftinfo[0];
            int rightbound = rightinfo[1] == -1 ? mid : rightinfo[1];
            return vector<int>{leftbound, rightbound};
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        return f(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end
