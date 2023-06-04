/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> arr(n + 2, 0);
        arr[n + 1] = 0;
        arr[n] = 1;
        for (int i = n - 1; i >= 0; i--)
            arr[i] = arr[i + 1] + arr[i + 2];
        return arr[0];
    }

    int process(int n, int now)
    {
        if (now == n)
            return 1;
        if (now > n)
            return 0;
        return process(n, now + 1) + process(n, now + 2);
    }
};
// @lc code=end
