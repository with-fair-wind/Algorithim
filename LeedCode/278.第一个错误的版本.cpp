/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

bool isBadVersion(int version);

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;
        int res = 0;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (isBadVersion(mid))
            {
                right = mid - 1;
                res = mid;
            }
            else
                left = mid + 1;
        }
        return res;
    }
};
// @lc code=end
