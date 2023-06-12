/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> mapnums;
        for (const int &cur : nums)
        {
            if (mapnums.find(cur) == mapnums.end())
                mapnums[cur] = 1;
            else
                mapnums[cur]++;
        }
        auto iter = mapnums.begin();
        int res = 0;
        int prevcount = (*(iter)).second, prevnum = (*(iter)).first;
        iter++;
        for (; iter != mapnums.end(); iter++)
        {
            if (iter->first == (prevnum + 1))
                res = max(res, prevcount + iter->second);
            prevcount = iter->second;
            prevnum = iter->first;
        }

        return res;
    }
};
// @lc code=end
