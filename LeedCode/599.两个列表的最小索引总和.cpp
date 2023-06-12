/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        map<string, int> map1, map2;
        for (int i = 0; i < list1.size(); i++)
            map1[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++)
            map2[list2[i]] = i;
        vector<string> res;
        int minSumIndex = INT_MAX;
        for (auto iter = map1.begin(); iter != map1.end(); iter++)
        {
            if (map2.find(iter->first) != map2.end())
            {
                int nowSumIndex = iter->second + map2[iter->first];
                if (minSumIndex > nowSumIndex)
                {
                    res.clear();
                    res.push_back(iter->first);
                    minSumIndex = nowSumIndex;
                }
                else if (minSumIndex == nowSumIndex)
                    res.push_back(iter->first);
            }
        }
        return res;
    }
};
// @lc code=end
