/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == INT_MIN)
            return false;
        if (n != (n & (~n + 1)))
            return false;
        return n & 0x55555555;
    }
};
// @lc code=end
