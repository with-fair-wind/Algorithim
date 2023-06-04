/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
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
    bool isSymmetric(TreeNode *root)
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            if (root->left == nullptr && root->right == nullptr)
                return true;
            else
                return false;
        }
        return process(root->left, root->right);
    }

        bool process(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
        {
            if (left == nullptr && right == nullptr)
                return true;
            else
                return false;
        }
        if (left->val != right->val)
            return false;
        return process(left->right, right->left) && process(left->left, right->right);
    }
};
// @lc code=end
