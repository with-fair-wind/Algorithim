/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <map>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
            return false;
        map<char, int> mapch;
        for (const char &ch : magazine)
        {
            if (mapch.find(ch) == mapch.end())
                mapch[ch] = 1;
            else
                mapch[ch]++;
        }
        for (const char &ch : ransomNote)
        {
            if (mapch.find(ch) == mapch.end())
                return false;
            else
            {
                if (mapch[ch] == 0)
                    return false;
                else
                    mapch[ch]--;
            }
        }
        return true;
    }
};
// @lc code=end
