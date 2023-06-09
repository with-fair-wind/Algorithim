/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 15 != 0)
                res.push_back("Fizz");
            else if (i % 5 == 0 && i % 15 != 0)
                res.push_back("Buzz");
            else if (i % 15 == 0)
                res.push_back("FizzBuzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
// @lc code=end
