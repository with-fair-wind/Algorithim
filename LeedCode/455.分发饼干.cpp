/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int res = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                res++;
                i++;
                j++;
            }
            else
                j++;
        }
        return res;
    }
};
// @lc code=end
