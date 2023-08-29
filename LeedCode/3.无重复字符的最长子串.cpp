/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
#if 0
    int lengthOfLongestSubstring(string s)
    {
        return process(s, 0);
    }

    int process(string s, int index)
    {
        if (index == s.length())
            return 0;
        int nocur = process(s, index + 1);
        set<char> setch;
        setch.insert(s[index]);
        int cur = 1;
        for (int i = index + 1; i < s.length(); i++)
        {
            if (setch.find(s[i]) == setch.end())
            {
                cur++;
                setch.insert(s[i]);
            }
            else
                break;
        }
        return max(cur, nocur);
    }
#else
    int lengthOfLongestSubstring(string s)
    {
        int res = INT_MIN;
        int left = 0;
        int right = 0;
        map<char, int> setmap;
        int cur = 0;
        while (right < s.length())
        {
            auto iter = setmap.find(s[right]);
            if (iter == setmap.end())
            {
                setmap.insert(make_pair(s[right], right));
                right++;
            }
            else
            {
                res = max(res, right - left);
                int repeat = setmap[s[right]];
                for (int i = left; i < repeat + 1; i++)
                    setmap.erase(s[i]);
                left = repeat + 1;
            }
        }
        return max(res, right - left);
    }
#endif
};
// @lc code=end
