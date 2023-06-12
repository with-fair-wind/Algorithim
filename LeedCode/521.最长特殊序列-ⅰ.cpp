/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

#include <cmath>
#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        map<char, int> map1, map2;
        for (const char &ch : a)
        {
            if (map1.find(ch) != map1.end())
                map1[ch]++;
            else
                map1[ch] = 1;
        }
        for (const char &ch : b)
        {
            if (map2.find(ch) != map2.end())
                map2[ch]++;
            else
                map2[ch] = 1;
        }
        for (auto const &cur : map1)
        {
            if (map2.find(cur.first) == map2.end())
                return max(a.length(), b.length());
        }
        for (auto const &cur : map2)
        {
            if (map1.find(cur.first) == map1.end())
                return max(a.length(), b.length());
        }
        return a == b ? -1 : max(a.length(), b.length());
    }
};
// @lc code=end
