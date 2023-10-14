// @before-stub-for-debug-begin
#include "commoncppproblem189.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int count = (nums.size() - k % nums.size());

        nums.insert(nums.end(), nums.begin(), nums.begin() + count);
        nums.erase(nums.begin(), nums.begin() + count);
    }
};
// @lc code=end
