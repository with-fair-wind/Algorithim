// @before-stub-for-debug-begin
#include "commoncppproblem219.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <map>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        return ans1(nums, k);
    }

    bool ans1(vector<int> &nums, int k)
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

    bool ans2(vector<int> &nums, int k)
    {
        if (k == 0)
            return false;
        deque<int> dequenum;

        for (int i = 0; i < nums.size(); i++)
        {
            if (dequenum.empty())
                dequenum.push_back(nums[i]);
            else
            {
                if (dequenum.size() < k)
                {
                    for (int j = 0; j < dequenum.size(); j++)
                    {
                        if (dequenum[j] == nums[i])
                            return true;
                    }
                    dequenum.push_back(nums[i]);
                }
                else
                {
                    for (int j = 0; j < dequenum.size(); j++)
                    {
                        if (dequenum[j] == nums[i])
                            return true;
                    }
                    dequenum.pop_front();
                    dequenum.push_back(nums[i]);
                }
            }
        }
        return false;
    }
};
// @lc code=end
