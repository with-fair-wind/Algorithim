/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res += nums[i];
        return nums.size() * (nums.size() + 1) / 2 - res;
    }
};
// @lc code=end
