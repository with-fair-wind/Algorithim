/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int l = 0, r = 1;
        while (r < nums.size())
        {
            if (nums[r] == nums[l])
                r++;
            else
                nums[++l] = nums[r++];
        }
        return l + 1;
    }
};
// @lc code=end
