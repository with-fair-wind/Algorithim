// @before-stub-for-debug-begin
#include "commoncppproblem367.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 0, right = num;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if ((long long)mid * mid == num)
                return true;
            else if ((long long)mid * mid < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
// @lc code=end
