// @before-stub-for-debug-begin
#include "commoncppproblem345.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

#include <set>
#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        set<char> setch{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            while (setch.find(s[left]) == setch.end() || setch.find(s[right]) == setch.end())
            {
                if (left >= right)
                    return s;
                if (setch.find(s[left]) == setch.end())
                    left++;
                if (setch.find(s[right]) == setch.end())
                    right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};
// @lc code=end
