/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start

#include <queue>
#include <sstream>
#include <string>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        return serialByPre(root);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        return reconByPreString(data);
    }

    string serialByPre(TreeNode *head)
    {
        if (head == nullptr)
            return "#_";
        string res = to_string(head->val) + "_";
        res += serialByPre(head->left);
        res += serialByPre(head->right);
        return res;
    }

    TreeNode *reconByPreString(string preStr)
    {
        stringstream ss(preStr);
        queue<string> strQueue;
        string temp;
        while (getline(ss, temp, '_'))
        {
            if (!temp.empty())
                strQueue.push(temp);
        }
        return reconPreOrder(strQueue);
    }

    TreeNode *reconPreOrder(queue<string> &strQueue)
    {
        if (strQueue.empty())
            return nullptr;
        string strFront = strQueue.front();
        strQueue.pop();
        if (strFront == "#")
            return nullptr;
        TreeNode *head = new TreeNode(stoi(strFront));
        head->left = reconPreOrder(strQueue);
        head->right = reconPreOrder(strQueue);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
