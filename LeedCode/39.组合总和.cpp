// @before-stub-for-debug-begin
#include "commoncppproblem39.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        f(candidates, 0, path, target, result);
        return result;
    }

    void f(const vector<int> &candiates, int index, vector<int> &path, int target, vector<vector<int>> &res)
    {
        if (!target)
        {
            res.push_back(path);
            return;
        }
        if (index == candiates.size() || target < 0)
            return;

        for (int num = 0; candiates[index] * num <= target; ++num)
        {
            for (int i = 0; i < num; ++i)
                path.push_back(candiates[index]);
            f(candiates, index + 1, path, target - num * candiates[index], res);
            for (int i = 0; i < num; ++i)
                path.pop_back();
        }
    }
};
// @lc code=end
