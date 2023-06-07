/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        map<int, int> mapnums;
        for (const int &cur : nums1)
        {
            if (mapnums.find(cur) == mapnums.end())
                mapnums[cur] = 1;
            else
                mapnums[cur]++;
        }
        for (const int &cur : nums2)
        {
            if (mapnums.find(cur) != mapnums.end())
            {
                if (mapnums[cur])
                {
                    res.push_back(cur);
                    mapnums[cur]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
