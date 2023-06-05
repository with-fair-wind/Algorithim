/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        long tmp = n;
        if (!tmp)
            return false;
        return tmp == (tmp & (~tmp + 1));
    }
};
// @lc code=end
