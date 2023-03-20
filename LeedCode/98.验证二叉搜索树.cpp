/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <cstdlib>
#include <list>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        // list<long> myList;
        // process(root, myList);
        // long prev = LONG_MIN;
        // for (long num : myList)
        // {
        //     if (num <= prev)
        //         return false;
        //     prev = num;
        // }
        // return true;

        return process_v2(root)->first;
    }

    void process(TreeNode *head, list<long> &myList)
    {
        if (head == nullptr)
            return;
        process(head->left, myList);
        myList.push_back(head->val);
        process(head->right, myList);
    }

    pair<bool, pair<int, int>> *process_v2(TreeNode *head)
    {
        if (head == nullptr)
            return nullptr;
        pair<bool, pair<int, int>> *left = process_v2(head->left);
        pair<bool, pair<int, int>> *right = process_v2(head->right);
        int minNum = head->val, maxNum = head->val;
        if (left)
        {
            minNum = min(minNum, left->second.first);
            maxNum = max(maxNum, left->second.second);
        }
        if (right)
        {
            minNum = min(minNum, right->second.first);
            maxNum = max(maxNum, right->second.second);
        }
        bool isBST = true;
        if ((left != nullptr && (!left->first || left->second.second >= head->val)) ||
            (right != nullptr && (!right->first || right->second.first <= head->val)))
            isBST = false;
        return new pair<bool, pair<int, int>>(isBST, pair<int, int>(minNum, maxNum));
    }
};
// @lc code=end
