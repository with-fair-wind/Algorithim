/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <string>
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        string str = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
            res.push_back(str);
        else if (root->left != nullptr && root->right == nullptr)
        {
            vector<string> left = binaryTreePaths(root->left);
            for (int i = 0; i < left.size(); i++)
                res.push_back(str + "->" + left[i]);
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            vector<string> right = binaryTreePaths(root->right);
            for (int i = 0; i < right.size(); i++)
                res.push_back(str + "->" + right[i]);
        }
        else
        {
            vector<string> left = binaryTreePaths(root->left);
            vector<string> right = binaryTreePaths(root->right);
            for (int i = 0; i < left.size(); i++)
                res.push_back(str + "->" + left[i]);
            for (int i = 0; i < right.size(); i++)
                res.push_back(str + "->" + right[i]);
        }
        return res;
    }
};
// @lc code=end
