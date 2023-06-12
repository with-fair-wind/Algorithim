/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int count = 0, tmp = 0;
        bool isL = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                if (++count == 2)
                    return false;
            }
            if (s[i] == 'L' && !isL)
            {
                isL = true;
                tmp++;
            }
            else if (s[i] == 'L' && isL)
            {
                if (++tmp == 3)
                    return false;
            }
            else if (s[i] != 'L' && isL)
            {
                tmp = 0;
                isL = false;
            }
        }
        return true;
    }
};
// @lc code=end
