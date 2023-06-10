/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
#ifdef ANS1
        vector<int> res;
        set<int> setnums;
        for (int i = 0; i < nums.size(); i++)
            setnums.insert(nums[i]);
        for (int i = 1; i <= nums.size(); i++)
        {
            if (setnums.find(i) == setnums.end())
                res.push_back(i);
        }
        return res;
#endif

        int length = nums.size();
        // 将nums数组中所有可能数 - 1作为下标的对应值 > n
        for (auto &cur : nums)
        {
            int index = (cur - 1) % length;
            nums[index] += length;
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= length)
                res.push_back(i + 1);

        return res;
    }
};
// @lc code=end
