// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem697.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int res = INT_MAX, maxCounts = 1, maxLength;
        map<int, pair<int, int>> mapnum;
        bool isChange = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mapnum.find(nums[i]) == mapnum.end())
                mapnum[nums[i]] = make_pair(1, i);
            else
            {
                ++mapnum[nums[i]].first;
                if (maxCounts < mapnum[nums[i]].first)
                {
                    maxCounts = mapnum[nums[i]].first;
                    isChange = true;
                }
                if (isChange)
                    res = i - mapnum[nums[i]].second + 1;
                else
                {
                    if (maxCounts == mapnum[nums[i]].first)
                        res = std::min(res, i - mapnum[nums[i]].second + 1);
                }
                isChange = false;
            }
        }
        return res == INT_MAX ? 1 : res;
    }
};
// @lc code=end
