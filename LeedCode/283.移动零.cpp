/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonzeroes = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                nums[nonzeroes++] = nums[i];
        for (int i = nonzeroes; i < nums.size(); i++)
            nums[i] = 0;
    }
};
// @lc code=end
