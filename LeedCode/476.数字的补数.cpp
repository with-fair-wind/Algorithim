// @before-stub-for-debug-begin
#include "commoncppproblem476.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        int res = 0;
        bool bstart = false;
        for (int i = 31; i >= 0; i--)
        {
            int tmp = (~num & 1 << i);
            if (tmp == 0)
                bstart = true;
            if (bstart)
                res += tmp;
        }
        return res;
    }
};
// @lc code=end
