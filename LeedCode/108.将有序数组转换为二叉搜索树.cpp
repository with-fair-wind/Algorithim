/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

// Definition for a binary tree node.

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return process(nums, 0, nums.size() - 1);
    }

    TreeNode *process(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = process(nums, left, mid - 1);
        node->right = process(nums, mid + 1, right);
        return node;
    }
};
// @lc code=end
