/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        nums.push_back(0);
        int length = INT_MIN;
        int prev = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
            {
                length = max(i - prev - 1, length);
                prev = i;
            }
        }
        return prev == -1 ? nums.size() : length;
    }
};
// @lc code=end
