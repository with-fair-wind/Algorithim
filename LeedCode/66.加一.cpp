// @before-stub-for-debug-begin
#include "commoncppproblem66.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result = digits;
        int add = 1;
        auto iter = result.rbegin();
        while (add)
        {
            while (iter != result.rend())
            {
                *iter = ((((*iter) + add) == 10) ? 0 : (*iter) + add);
                add = ((*iter == 0) ? 1 : 0);
                iter++;
                break;
            }
            if (add == 1 && iter == result.rend())
            {
                result.insert(result.begin(), 1);
                add = 0;
            }
        }
        return result;
    }
};
// @lc code=end
