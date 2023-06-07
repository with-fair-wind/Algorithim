/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }

    // 暴力方法，打印后找规律
    int ans1(int num)
    {
        if (num < 10)
            return num;
        int next = num % 10;
        while (num)
        {
            num /= 10;
            next += (num % 10);
        }
        return addDigits(next);
    }
};
// @lc code=end
