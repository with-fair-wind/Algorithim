/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    string ManacherString(const string &str)
    {
        string output;
        for (char c : str)
        {
            output += '#';
            output += c;
        }
        output += '#';
        return output;
    }

    string longestPalindrome(string s)
    {
        return Manacher(s);
    }

    string Manacher(const string &str)
    {
        if (str.length() < 1)
            return 0;
        string fixStr = ManacherString(str);
        int MaxLen = INT_MIN;
        string res;
        int maxPalindRadius[fixStr.length()];
        // 回文半径包括中间的那个，比如bab,回文半径是2
        // R代表之前所有扩的位置中所到达所有最右回文最右边界的下一个位置，就是如果发现i对应的最长回文半径更大后，就更新R这个边界,R只会递增
        // R递增Center就更新(右边界突破了就更新)(同步更新)
        int R = -1, Center = -1;
        for (int i = 0; i < static_cast<int>(fixStr.length()); i++)
        {
            maxPalindRadius[i] = R > i ? min(maxPalindRadius[2 * Center - i], R - i) : 1;
            while (i + maxPalindRadius[i] < static_cast<int>(fixStr.length()) && i - maxPalindRadius[i] > -1)
            {
                if (fixStr[i + maxPalindRadius[i]] == fixStr[i - maxPalindRadius[i]])
                    maxPalindRadius[i]++;
                else
                    break;
            }
            if (i + maxPalindRadius[i] > R)
            {
                R = i + maxPalindRadius[i];
                Center = i;
            }
            // 以上才是重点,求出每个索引对应的最长回文子串长度
            if (MaxLen < maxPalindRadius[i])
            {
                MaxLen = maxPalindRadius[i];
                res = getPalind(fixStr, i, maxPalindRadius[i]);
            }
        }
        return res;
    }

    string getPalind(const string &str, int index, int radius)
    {
        string res;
        for (int i = 1 - radius; i < radius; ++i)
            res += str[index + i];
        res.erase(std::remove_if(res.begin(), res.end(), [](char c)
                                 { return c == '#'; }),
                  res.end());
        return res;
    }
};
// @lc code=end
