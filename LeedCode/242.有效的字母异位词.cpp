/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <map>
#include <string>
#include <utility>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        map<char, int> chmap;
        for (int i = 0; i < s.length(); i++)
        {
            if (chmap.find(s[i]) == chmap.end())
                chmap[s[i]] = 1;
            else
                chmap[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            if (chmap.find(t[i]) == chmap.end())
                return false;
            else
                chmap[t[i]]--;
        }
        for (const auto &cur : chmap)
        {
            if (cur.second != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
