/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> setnums, setres;
        for (const int &cur : nums1)
            setnums.insert(cur);
        for (const int &cur : nums2)
            if (setnums.find(cur) != setnums.end())
                setres.insert(cur);

        return vector<int>(setres.begin(), setres.end());
    }
};
// @lc code=end
