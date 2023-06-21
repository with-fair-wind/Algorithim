// @before-stub-for-debug-begin
#include "commoncppproblem696.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int result = 0, count = 0;
        int i = 0;
        while (i < s.length())
        {
            count = 0;
            int j = i;
            while (s[j] == s[i] && j < s.length())
            {
                count++;
                j++;
            }
            char ch;
            int tmp = count, next = j;
            if (j != s.length())
                ch = s[j];
            while (s[j] == ch && j < s.length() && count > 0)
            {
                count--;
                j++;
            }
            if (!count)
                result += tmp;
            else
                result += (tmp - count);
            i = next;
        }
        return result;
    }
};
// @lc code=end
