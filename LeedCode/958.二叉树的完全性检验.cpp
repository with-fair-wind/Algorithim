/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> myQueue;
        myQueue.push(root);
        TreeNode *left = nullptr, *right = nullptr;
        bool remain = false;
        while (!myQueue.empty())
        {
            TreeNode *cur = myQueue.front();
            myQueue.pop();
            if ((remain && (cur->left != nullptr || cur->right != nullptr)) ||
                (cur->right != nullptr && cur->left == nullptr))
                return false;
            if (cur->left == nullptr || cur->right == nullptr)
                remain = true;
            if (cur->left)
                myQueue.push(cur->left);
            if (cur->right)
                myQueue.push(cur->right);
        }
        return true;
    }
};
// @lc code=end
