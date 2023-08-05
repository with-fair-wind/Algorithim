// @before-stub-for-debug-begin
#include "commoncppproblem704.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int L = 0, R = nums.size() - 1;
        return process(nums, target, L, R);
    }

    int process(vector<int> &nums, int target, int L, int R)
    {
        if (L >= R && nums[L] != target)
            return -1;
        int mid = L + ((R - L) >> 1);
        if (nums[mid] == target)
            return mid;
        return nums[mid] < target ? process(nums, target, mid + 1, R) : process(nums, target, L, mid - 1);
    }
};
// @lc code=end
