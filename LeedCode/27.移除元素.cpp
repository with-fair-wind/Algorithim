// @before-stub-for-debug-begin
#include "commoncppproblem27.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
#if 0
    int removeElement(vector<int> &nums, int val)
    {
        int end = nums.size() - 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= end)
            {
                while (nums[i] == val)
                {
                    if (i != end)
                        swap(nums[i], nums[end--]);
                    else
                        break;
                }
                if (nums[i] != val)
                    res++;
            }
        }
        return res;
    }
#else if
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
#endif
};
// @lc code=end
