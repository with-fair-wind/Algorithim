// @before-stub-for-debug-begin
#include "commoncppproblem20.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <stack>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> mapStr;
        mapStr.insert(make_pair('(', ')'));
        mapStr.insert(make_pair('[', ']'));
        mapStr.insert(make_pair('{', '}'));
        stack<char> stackStr;
        if (s.length() & 1)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (mapStr.find(s[i]) != mapStr.end())
            {
                stackStr.push(s[i]);
                continue;
            }
            if (!stackStr.empty())
            {
                if (mapStr[stackStr.top()] != s[i])
                    return false;
                stackStr.pop();
                continue;
            }
            else
                return false;
        }
        return stackStr.empty() ? true : false;
    }
};
// @lc code=end
