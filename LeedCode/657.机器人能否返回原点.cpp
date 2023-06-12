/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

#include <string>

using namespace std;

// @lc code=start
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int arr[4] = {};
        for (const char &cur : moves)
        {
            switch (cur)
            {
            case 'R':
                arr[0]++;
                break;
            case 'L':
                arr[1]++;
                break;
            case 'U':
                arr[2]++;
                break;
            case 'D':
                arr[3]++;
                break;
            }
        }
        return arr[0] == arr[1] && arr[2] == arr[3];
    }
};
// @lc code=end
