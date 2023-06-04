// @before-stub-for-debug-begin
#include "commoncppproblem35.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        return process(nums, target, 0, nums.size() - 1);
    }

    int process(vector<int> &nums, int target, int left, int right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target)
            return mid;
        if (right == left)
            return nums[left] < target ? left + 1 : left;
        return nums[mid] < target ? process(nums, target, mid + 1, right) : process(nums, target, left, mid);
    }
};
// @lc code=end
