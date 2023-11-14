// @before-stub-for-debug-begin
#include "commoncppproblem209.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int res = INT_MAX;
        int L = 0, R = 0, cur = 0;
        for (; R < nums.size(); R++)
        {
            cur += nums[R];
            while (cur - nums[L] >= target)
                cur -= nums[L++];
            if (cur >= target)
                res = min(res, R - L + 1);
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
