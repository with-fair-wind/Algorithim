// @before-stub-for-debug-begin
#include "commoncppproblem643.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        int curSum = 0;
        for (int i = 0; i < k; i++)
            curSum += nums[i];
        int maxSum = curSum;
        for (int i = 1; i <= nums.size() - k; i++)
        {
            curSum = curSum - nums[i - 1] + nums[i + k - 1];
            maxSum = max(maxSum, curSum);
        }
        return (double)maxSum / (double)k;
    }
};
// @lc code=end
