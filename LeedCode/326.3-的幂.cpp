/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        while (n != 1)
        {
            if (n % 3 == 0)
                n /= 3;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
