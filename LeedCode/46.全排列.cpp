// @before-stub-for-debug-begin
#include "commoncppproblem46.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
#if 0
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        set<int> visited;
        f(nums, 0, path, visited, res);
        return res;
    }

    void f(vector<int> &nums, int index, vector<int> &path, set<int> &visited, vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {

            if (visited.find(nums[i]) == visited.end())
            {
                mswap(nums, i, index);
                visited.insert(nums[i]);
                path.push_back(nums[i]);
                f(nums, index + 1, path, visited, res);
                path.pop_back();
                visited.erase(nums[i]);
                mswap(nums, i, index);
            }
        }
    }
#else
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        f(nums, 0, res);
        return res;
    }

    void f(vector<int> &nums, int index, vector<vector<int>> &res)
    {
        if (index == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            mswap(nums, i, index);
            f(nums, index + 1, res);
            mswap(nums, i, index);
        }
    }
#endif

    void mswap(vector<int> &nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};
// @lc code=end
