/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
    int f(const vector<int> &nums, int L, int R, int target)
    {
        if (L == R)
            return nums[L] == target ? L : -1;
        int mid = L + ((R - L) >> 1);
        int leftinfo = f(nums, L, mid, target);
        int rightinfo = f(nums, mid + 1, R, target);
        return leftinfo == -1 ? rightinfo : leftinfo;
    }

public:
    int search(vector<int> &nums, int target)
    {
        return f(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end
