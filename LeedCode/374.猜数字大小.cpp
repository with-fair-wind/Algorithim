/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */
int guess(int num);
// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int tmp = guess(mid);
            if (tmp == 0)
                return mid;
            else if (tmp == -1)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
// @lc code=end
