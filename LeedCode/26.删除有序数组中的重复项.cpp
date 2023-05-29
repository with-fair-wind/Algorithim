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
        set<int> numSet;
        int length = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (numSet.find(nums[i]) == numSet.end())
            {
                numSet.insert(nums[i]);
                length++;
            }
        }
        nums.clear();
        copy(numSet.begin(), numSet.end(), back_inserter(nums));
        return length;
    }
};
// @lc code=end
