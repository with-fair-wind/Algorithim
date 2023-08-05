// @before-stub-for-debug-begin
#include "commoncppproblem747.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        pair<int, int> p = findmax(nums, 0, nums.size() - 1);
        int cmp = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cmp < nums[i] && nums[i] < p.second)
                cmp = nums[i];
        }
        return p.second >= 2 * cmp ? p.first : -1;
    }

    pair<int, int> findmax(vector<int> &nums, int L, int R)
    {
        if (L == R)
            return make_pair(L, nums[L]);
        int mid = L + ((R - L) >> 1);
        pair<int, int> maxleft = findmax(nums, L, mid);
        pair<int, int> maxright = findmax(nums, mid + 1, R);
        return maxleft.second < maxright.second ? maxright : maxleft;
    }
};
// @lc code=end
