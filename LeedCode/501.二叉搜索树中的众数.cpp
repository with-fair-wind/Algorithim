// @before-stub-for-debug-begin
#include "commoncppproblem501.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include <map>
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
// @lc code=start

// Definition for a binary tree node.

class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;

        int base = INT_MIN, count, maxCount = INT_MIN;

        stack<TreeNode *> stackNode;
        while (root)
        {
            stackNode.push(root);
            root = root->left;
        }
        while (!stackNode.empty())
        {
            TreeNode *node = stackNode.top();
            stackNode.pop();

            if (node->val == base)
                count++;
            else
            {
                base = node->val;
                count = 1;
            }
            if (maxCount == count)
                result.push_back(node->val);
            else if (count > maxCount)
            {
                maxCount = count;
                result = vector<int>{node->val};
            }

            node = node->right;
            while (node)
            {
                stackNode.push(node);
                node = node->left;
            }
        }
        return result;
    }
};
// @lc code=end
