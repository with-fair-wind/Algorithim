/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> chmap;
        unordered_set<char> chset;
        for (int i = 0; i < s.length(); i++)
        {
            if (chmap.find(s[i]) == chmap.end())
            {
                if (chset.find(t[i]) == chset.end())
                {
                    chmap[s[i]] = t[i];
                    chset.insert(t[i]);
                }
                else
                    return false;
            }
            else
            {
                if (chmap[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
