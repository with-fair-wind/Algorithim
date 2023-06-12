/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include <algorithm>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int count = s.length();
        int start = 0;
        while (count >= 2 * k)
        {
            int end = start + k - 1;
            int next = start + 2 * k;
            while (start < end)
                swap(s[start++], s[end--]);
            start = next;
            count -= 2 * k;
        }
        int end = count < k ? s.size() - 1 : start + k - 1;
        while (start < end)
            swap(s[start++], s[end--]);
        return s;
    }
};
// @lc code=end
