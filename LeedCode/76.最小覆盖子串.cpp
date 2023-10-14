// @before-stub-for-debug-begin
#include "commoncppproblem76.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        std::unordered_map<char, int> tCharCount;
        for (char c : t)
            tCharCount[c]++;

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int requiredChars = tCharCount.size();
        int matchedChars = 0;
        std::unordered_map<char, int> windowCharCount;

        while (right < s.length())
        {
            char rightChar = s[right];
            windowCharCount[rightChar]++;

            if (tCharCount.find(rightChar) != tCharCount.end() && windowCharCount[rightChar] == tCharCount[rightChar])
            {
                matchedChars++;
            }

            while (matchedChars == requiredChars && left <= right)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCharCount[leftChar]--;

                if (tCharCount.find(leftChar) != tCharCount.end() && windowCharCount[leftChar] < tCharCount[leftChar])
                {
                    matchedChars--;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX)
        {
            return "";
        }

        return s.substr(minStart, minLen);
    }
};
// @lc code=end
