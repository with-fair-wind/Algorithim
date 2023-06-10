/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> setnums;
        for (const int &cur : nums)
            setnums.insert(cur);
        auto iter = setnums.rbegin();
        advance(iter, 2);
        return setnums.size() < 3 ? *(setnums.rbegin()) : *iter;
    }
};
// @lc code=end
