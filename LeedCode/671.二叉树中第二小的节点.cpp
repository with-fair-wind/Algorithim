/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */
#include <set>

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
    set<int> m_set;

    int findSecondMinimumValue(TreeNode *root)
    {
        process(root);
        auto it = m_set.begin();
        return ++it == m_set.end() ? -1 : *it;
    }

    void process(TreeNode *root)
    {
        if (root == nullptr)
            return;
        m_set.insert(root->val);
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);
    }
};
// @lc code=end
