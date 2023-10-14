// @before-stub-for-debug-begin
#include "commoncppproblem80.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int L = 0, R = 1, mid = 0;
        bool isRepeat = false;
        if (nums.size() == 1)
            return 1;
        while (R < nums.size())
        {
            if (nums[L] == nums[R])
            {
                R++;
                isRepeat = true;
            }
            else
            {
                if (!isRepeat)
                    nums[++L] = nums[R++];
                else
                {
                    nums[L + 1] = nums[L];
                    nums[L + 2] = nums[R++];
                    L += 2;
                }
                isRepeat = false;
            }
        }
        if (isRepeat)
            nums[++L] = nums.back();

        return L + 1;
    }
};
// @lc code=end
