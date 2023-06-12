/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 */

#include <cmath>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int tmp = sqrt(num), cur = 1;
        for (int i = 2; i <= tmp; i++)
            if (num % i == 0)
                cur += (i + num / i);
        return cur == num;
    }
};
// @lc code=end
