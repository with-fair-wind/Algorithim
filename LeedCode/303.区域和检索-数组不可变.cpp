/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

#include <vector>

using namespace std;

// @lc code=start
class NumArray
{
private:
    vector<int> m_table;

public:
    NumArray(vector<int> &nums)
    {
        m_table.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            m_table.push_back(m_table[i - 1] + nums[i]);
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? m_table[right] : m_table[right] - m_table[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
