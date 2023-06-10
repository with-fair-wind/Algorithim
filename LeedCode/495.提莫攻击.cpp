/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int result = 0;
        int last, tmp;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            last = timeSeries[i] + duration - 1;
            if (i + 1 < timeSeries.size())
            {
                result += last < timeSeries[i + 1] ? duration : timeSeries[i + 1] - timeSeries[i];
            }
            else
                result += duration;
        }
        return result;
    }
};
// @lc code=end
