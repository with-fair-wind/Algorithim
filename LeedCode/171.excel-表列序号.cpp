/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

#include <cmath>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        string tmp = string(columnTitle.rbegin(), columnTitle.rend());
        int res = 0;
        for (int i = 0; i < tmp.length(); i++)
            res += (tmp[i] - 'A' + 1) * pow(26, i);
        return res;
    }
};
// @lc code=end
