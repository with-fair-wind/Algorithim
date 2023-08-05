// @before-stub-for-debug-begin
#include "commoncppproblem724.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        int lsum = 0, rsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0)
                lsum += nums[i - 1];
            rsum = sum - lsum - nums[i];
            if (rsum == lsum)
                return i;
        }
        return -1;
    }
};
// @lc code=end
