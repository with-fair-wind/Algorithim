// @before-stub-for-debug-begin
#include "commoncppproblem409.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

#include <cmath>
#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int res = 0;
        bool btmp = false;
        map<char, int> mapch;
        for (const char &cur : s)
        {
            if (mapch.find(cur) == mapch.end())
                mapch[cur] = 1;
            else
                mapch[cur]++;
        }
        for (const auto &cur : mapch)
        {
            if ((cur.second & 1) == 0)
                res += cur.second;
            else
            {
                btmp = true;
                res += cur.second - 1;
            }
        }
        return btmp ? res + 1 : res;
    }
};

// @lc code=end
