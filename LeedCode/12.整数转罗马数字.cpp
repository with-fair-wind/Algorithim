// @before-stub-for-debug-begin
#include "commoncppproblem12.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> romanvec{
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},

        };
        string res;
        for (const auto &cur : romanvec)
        {
            while (num >= cur.first)
            {
                num -= cur.first;
                res += cur.second;
            }
            if (num == 0)
                break;
        }
        return res;
    }
};
// @lc code=end
