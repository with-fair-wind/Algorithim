/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return process(root).first;
    }

    pair<bool, int> process(TreeNode *head)
    {
        if (head == nullptr)
            return make_pair(true, 0);
        pair<bool, int> p1 = process(head->left);
        pair<bool, int> p2 = process(head->right);
        int height = max(p1.second, p2.second) + 1;
        bool isBalanced = p1.first && p2.first && (abs(p1.second - p2.second) < 2) ? true : false;
        return make_pair(isBalanced, height);
    }
};
// @lc code=end
