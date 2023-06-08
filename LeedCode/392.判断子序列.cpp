// @before-stub-for-debug-begin
#include "commoncppproblem392.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{

public:
    bool isSubsequence(string s, string t)
    {
        // vector<string> childstr;
        // CreateChildStr(t, 0, childstr);
        // return find(childstr.begin(), childstr.end(), s) != childstr.end();

        int i = 0, j = 0;
        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        return i == s.length();
    }

    void CreateChildStr(string s, int index, vector<string> &childStr)
    {
        if (index == s.length())
            return;
        if (index == s.length() - 1)
        {
            childStr.push_back(string(1, s[s.length() - 1]));
            return;
        }
        CreateChildStr(s, index + 1, childStr);
        for (int i = 0; i < childStr.size(); i++)
            childStr.push_back(s[index] + childStr[i]);
        return;
    }
};
// @lc code=end
