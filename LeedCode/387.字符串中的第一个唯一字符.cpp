// @before-stub-for-debug-begin
#include "commoncppproblem387.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include <map>
#include <string>
#include <utility>

using namespace std;

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, pair<int, bool>> mapch;
        for (int i = 0; i < s.length(); i++)
        {
            if (mapch.find(s[i]) == mapch.end())
                mapch[s[i]] = make_pair(i, true);
            else
                mapch[s[i]].second = false;
        }
        int res = INT_MAX;
        for (const auto &cur : mapch)
            if (cur.second.second)
                res = min(res, cur.second.first);
        if (res == INT_MAX)
            res = -1;
        return res;
    }
};
// @lc code=end
