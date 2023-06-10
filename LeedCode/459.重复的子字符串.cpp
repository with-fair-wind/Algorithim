// @before-stub-for-debug-begin
#include "commoncppproblem459.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return ans1(s);
    }

    bool ans1(string s)
    {
        if (s.length() == 1)
            return false;
        for (int i = 0; i < s.length() / 2; i++)
        {
            string tmp = s.substr(0, i + 1);
            if (s.length() % tmp.length() == 0)
            {
                int count = s.length() / tmp.length();
                string repeat;
                for (int j = 0; j < count; j++)
                    repeat += tmp;
                if (repeat == s)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
