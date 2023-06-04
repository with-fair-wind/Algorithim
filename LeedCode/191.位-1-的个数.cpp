/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include <stdint.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
            res += n & (1 << i) ? 1 : 0;
        return res;
    }
};
// @lc code=end
