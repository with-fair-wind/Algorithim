// @before-stub-for-debug-begin
#include "commoncppproblem645.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int repeat, lose, cmp = 1, prev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                repeat = nums[i];
                break;
            }
            else
                prev = nums[i];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != cmp)
            {
                lose = cmp;
                break;
            }
            else if (nums[i] == repeat)
                i++;
            cmp++;
        }
        return vector<int>{repeat, lose};
        // return ans1(nums);
    }

    vector<int> ans1(vector<int> &nums)
    {
        set<int> setnums;
        int repeat, lose;
        for (int i = 0; i < nums.size(); i++)
        {
            if (setnums.find(nums[i]) == setnums.end())
                setnums.insert(nums[i]);
            else
                repeat = nums[i];
        }
        int cmp = 1;
        for (auto iter = setnums.begin(); iter != setnums.end(); iter++)
        {
            if (*iter != cmp)
            {
                lose = cmp;
                break;
            }
            else
                cmp++;
        }
        return vector<int>{repeat, lose};
    }
};
// @lc code=end
