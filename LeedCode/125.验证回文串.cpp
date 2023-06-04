/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                       { return std::tolower(c); });
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c)
                               { return !std::isalnum(c); }),
                s.end());
        return string(s.rbegin(), s.rend()) == s;
    }
};
// @lc code=end
