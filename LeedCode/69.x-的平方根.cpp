// @before-stub-for-debug-begin
#include "commoncppproblem69.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        return process(x, 0, x);
    }

    int process(int x, int left, int right)
    {
        if (left == right)
            return left;
        if (left == right - 1)
            return right * right <= x ? right : left;
        int mid = left + ((right - left) >> 1);
        if ((long long)mid * mid == x)
            return mid;
        else if ((long long)mid * mid < x)
            return process(x, mid, right);
        else
            return process(x, left, mid - 1);
    }
};
// @lc code=end
