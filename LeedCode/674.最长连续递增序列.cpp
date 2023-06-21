// @before-stub-for-debug-begin
#include "commoncppproblem674.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

#include <cmath>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int result = 1;
        int L = 0, R = 0;
        while (R < nums.size())
        {
            if (R > 0 && nums[R] <= nums[R - 1])
            {
                result = max(result, R - L);
                L = R;
            }
            R++;
        }
        result = max(result, R - L);
        return L == 0 ? nums.size() : result;
    }
};
// @lc code=end
