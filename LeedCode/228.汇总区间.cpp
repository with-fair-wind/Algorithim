// @before-stub-for-debug-begin
#include "commoncppproblem228.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.empty())
            return vector<string>();
        vector<string> res;
        long begin = nums[0], end = begin, indexbegin = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            end = nums[i];
            if (end - begin != i - indexbegin)
            {
                if (indexbegin == i - 1)
                    res.push_back(to_string(nums[indexbegin]));
                else
                    res.push_back(to_string(nums[indexbegin]) + "->" + to_string(nums[i - 1]));
                indexbegin = i;
                begin = nums[indexbegin];
            }
        }
        if (indexbegin == nums.size() - 1)
            res.push_back(to_string(nums[indexbegin]));
        else
            res.push_back(to_string(nums[indexbegin]) + "->" + to_string(nums.back()));
        return res;
    }
};
// @lc code=end
