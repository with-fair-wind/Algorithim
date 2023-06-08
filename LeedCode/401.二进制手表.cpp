/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

#include <cmath>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> res;
        vector<int> bits(10, 0);

        backtrack(turnedOn, 0, 0, bits, res);
        return res;
    }

    // 从start位置开始选，已经选中的数量是count个，被选中的总数为turnedOn, bits是当前的手表状态，所有可能性是res
    void backtrack(int turnedOn, int start, int count, vector<int> &bits, vector<string> &res)
    {
        if (turnedOn == count)
        {
            int hour = 0, minute = 0;
            for (int i = 0; i < 4; i++)
                hour += bits[i] * pow(2, 3 - i);
            for (int i = 4; i < 10; i++)
                minute += bits[i] * pow(2, 9 - i);
            if (hour < 12 && minute < 60)
            {
                string str = to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
                res.push_back(str);
            }
            return;
        }
        for (int i = start; i < 10; i++)
        {
            bits[i] = 1;
            backtrack(turnedOn, i + 1, count + 1, bits, res);
            bits[i] = 0;
        }
    }
};
// @lc code=end
