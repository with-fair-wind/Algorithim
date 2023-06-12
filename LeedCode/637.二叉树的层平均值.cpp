/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */
#include <queue>
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> queueTree;
        vector<double> result;
        queueTree.push(root);
        TreeNode *curend = root, *nextend = nullptr, *cur = nullptr;
        double curSum = 0.0, count = 0.0;
        while (!queueTree.empty())
        {
            cur = queueTree.front();
            queueTree.pop();
            curSum += cur->val;
            count++;
            if (cur->left)
            {
                queueTree.push(cur->left);
                nextend = cur->left;
            }
            if (cur->right)
            {
                queueTree.push(cur->right);
                nextend = cur->right;
            }
            if (cur == curend)
            {
                curend = nextend;
                nextend = nullptr;
                double avg = (double)curSum / (double)count;
                result.push_back(avg);
                curSum = 0;
                count = 0;
            }
        }
        return result;
    }
};
// @lc code=end
