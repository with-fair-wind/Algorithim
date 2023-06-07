/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }

    bool ans1(int n)
    {
        if (n == 0)
            return false;
        if (n < 4)
            return true;
        bool res = false;
        for (int i = 1; i < 4; i++)
            res |= !canWinNim(n - i);
        return res;
    }
};
// @lc code=end
