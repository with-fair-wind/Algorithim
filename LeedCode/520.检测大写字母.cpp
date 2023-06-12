/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */

#include <cctype>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.length() == 1)
            return true;
        bool isBig = isupper(word[1]);
        if (isBig && islower(word[0]))
            return false;
        for (int i = 2; i < word.length(); i++)
        {
            char ch = word[i];
            if (!isBig)
            {
                if (!islower(ch))
                    return false;
            }
            else
            {
                if (!isupper(ch))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
