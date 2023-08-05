/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int index = 0;
        while (index < bits.size())
        {
            if (index == bits.size() - 1)
                return true;
            if (!bits[index])
                index++;
            else
                index += 2;
        }
        return false;
    }
};
// @lc code=end
