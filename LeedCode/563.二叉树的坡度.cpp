/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */
#include <cmath>
#include <utility>

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
    int findTilt(TreeNode *root)
    {
        return process(root).first;
    }

    pair<int, int> process(TreeNode *root)
    {
        if (root == nullptr)
            return make_pair(0, 0);
        pair<int, int> leftInfo = process(root->left);
        pair<int, int> rightInfo = process(root->right);
        int leftnum = root->left == nullptr ? 0 : root->left->val;
        int rightnum = root->right == nullptr ? 0 : root->right->val;
        int sumChildren = leftInfo.second + rightInfo.second + leftnum + rightnum;
        int slopenow = abs(rightInfo.second + rightnum - leftInfo.second - leftnum);
        int slopAll = slopenow + leftInfo.first + rightInfo.first;
        return make_pair(slopAll, sumChildren);
    }
};
// @lc code=end
