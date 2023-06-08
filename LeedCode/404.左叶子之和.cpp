// @before-stub-for-debug-begin
#include "commoncppproblem404.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
#include <queue>

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        queue<pair<TreeNode *, char>> queuetree;
        queuetree.push(make_pair(root, 'H'));
        int res = 0;
        bool bhaschild = false;
        while (!queuetree.empty())
        {
            pair<TreeNode *, char> cur = queuetree.front();
            queuetree.pop();
            if (cur.first->left)
            {
                queuetree.push(make_pair(cur.first->left, 'L'));
                bhaschild = true;
            }
            if (cur.first->right)
            {
                queuetree.push(make_pair(cur.first->right, 'R'));
                bhaschild = true;
            }
            if (!bhaschild && cur.second == 'L')
                res += cur.first->val;
            bhaschild = false;
        }
        return res;
    }
};
// @lc code=end
