/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int tmp, prev, count = 0;
        while (n)
        {
            prev = tmp;
            tmp = n % 2;
            n /= 2;
            if (count >= 1)
            {
                if (prev == tmp)
                    return false;
                else
                    prev = tmp;
            }
            count++;
        }
        return true;
    }
};
// @lc code=end
