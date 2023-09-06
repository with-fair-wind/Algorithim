/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int L = 0;
        int R = height.size() - 1;
        int maxarea = INT_MIN;
        while (L < R)
            maxarea = height[L] < height[R] ? max(maxarea, (R - L) * height[L++]) : max(maxarea, (R - L) * height[R--]);
        return maxarea;
    }
};
// @lc code=end
