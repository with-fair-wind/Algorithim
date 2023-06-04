/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> mapnum;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mapnum.find(nums[i]) == mapnum.end())
                mapnum[nums[i]] = i;
            else
            {
                if (i - mapnum[nums[i]] <= k)
                    return true;
                else
                    mapnum[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end
