// @before-stub-for-debug-begin
#include "commoncppproblem543.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        return process_v5(root).first - 1;
    }

    pair<int, int> process_v5(TreeNode *head)
    {
        if (head == nullptr)
            return make_pair(0, 0);
        pair<int, int> leftInfo = process_v5(head->left);
        pair<int, int> rightInfo = process_v5(head->right);
        int maxDistance = std::max(leftInfo.second + rightInfo.second + 1, (std::max(leftInfo.first, rightInfo.first)));
        int maxHeight = std::max(leftInfo.second, rightInfo.second) + 1;
        return make_pair(maxDistance, maxHeight);
    }
};
// @lc code=end
