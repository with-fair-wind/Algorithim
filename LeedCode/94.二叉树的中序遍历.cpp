/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

// Definition for a binary tree node.

#include <stack>
#include <vector>

using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>();
        stack<TreeNode *> stackNode;
        vector<int> res;
        while (root)
        {
            stackNode.push(root);
            root = root->left;
        }
        while (!stackNode.empty())
        {
            TreeNode *node = stackNode.top();
            stackNode.pop();
            res.push_back(node->val);
            node = node->right;
            while (node)
            {
                stackNode.push(node);
                node = node->left;
            }
        }
        return res;
    }
};
// @lc code=end
