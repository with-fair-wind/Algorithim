/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        map<char, int> mapch;
        for (int i = 0; i < s.length(); i++)
        {
            if (mapch.find(s[i]) == mapch.end())
                mapch[s[i]] = 1;
            else
                mapch[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (mapch.find(t[i]) == mapch.end())
                return t[i];
            else
            {
                if (--mapch[t[i]] < 0)
                    return t[i];
            }
        }
        return '\0';
    }
};
// @lc code=end
