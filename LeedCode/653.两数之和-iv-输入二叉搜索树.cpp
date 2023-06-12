/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    set<int> setnums;
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        bool left = findTarget(root->left, k);
        if (left)
            return true;
        else
        {
            if (setnums.find(k - root->val) != setnums.end())
                return true;
            else
                setnums.insert(root->val);
        }
        bool right = findTarget(root->right, k);
        return right;
    }
};
// @lc code=end
