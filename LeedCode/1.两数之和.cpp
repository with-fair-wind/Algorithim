/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mapArr;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = mapArr.find(target - nums[i]);
            if (iter != mapArr.end())
                return {i, iter->second};
            mapArr.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
// @lc code=end
