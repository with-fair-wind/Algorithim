/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

#include <cmath>

using namespace std;

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        // return process(n, 1, 1);

        int row = 0;
        while (n >= row + 1)
        {
            row++;
            n -= row;
        }
        return row;
    }

    int process(int n, int row, int count)
    {
        if (n - count < (row + 1))
            return row;
        if (n - count == (row + 1))
            return row + 1;
        return process(n, row + 1, count + row + 1);
    }
};
// @lc code=end
