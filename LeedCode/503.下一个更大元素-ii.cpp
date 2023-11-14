/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; i++)
        {
            while (!stk.empty() && nums[stk.top()] < nums[i % n])
            {
                res[stk.top()] = nums[i % n];
                stk.pop();
            }
            if (i < n)
                stk.push(i);
        }
        return res;
    }
};
// @lc code=end
