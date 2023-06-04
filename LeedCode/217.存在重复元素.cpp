/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include <map>
#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> setNum;
        for (const int &cur : nums)
        {
            if (setNum.find(cur) == setNum.end())
                setNum.insert(cur);
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
