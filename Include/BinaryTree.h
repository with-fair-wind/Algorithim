#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include "Fun.h"
#include <list>
#include <queue>
#include <stack>

struct TreeNode
{
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int data = 0, TreeNode *L = nullptr, TreeNode *R = nullptr) : val(data), left(L), right(R) {}
};

struct PTreeNode
{
    int val = 0;
    PTreeNode *left = nullptr;
    PTreeNode *right = nullptr;
    PTreeNode *father = nullptr;
    PTreeNode(int data = 0, PTreeNode *L = nullptr, PTreeNode *R = nullptr, PTreeNode *P = nullptr) : val(data), left(L), right(R), father(P) {}
};

// 遍历二叉树递归实现
void preOrderRecur(TreeNode *head); // 先序遍历(头左右)也是深度遍历
void inOrderRecur(TreeNode *head);  // 中序遍历(左头右)
void posOrderRecur(TreeNode *head); // 后序遍历(左右头)

// 遍历二叉树非递归实现，手动压栈
void preOrderUnRecur(TreeNode *head);
void inOrderUnRecur(TreeNode *head);
void posOrderUnRecur(TreeNode *head);

// 获得二叉树的最大宽度
int getMaxWidth(TreeNode *head);

// 判断是否是搜索二叉树(中序遍历递增)
bool isBST_v1(TreeNode *head);
void process_v1(TreeNode *head, std::list<int> &myList);
bool isBST_v2(TreeNode *head);
std::pair<bool, std::pair<int, int>> *process_v2(TreeNode *head);
// 判断是否是完全二叉树
bool isCBT(TreeNode *head);
// 判断是否是平衡二叉树
bool isBalanced(TreeNode *head);
std::pair<bool, int> process_v3(TreeNode *head);
// 判断是否是满二叉树
bool isFull(TreeNode *head);

// 给定两个二叉树的节点node1和node2，找它们公共祖先节点
TreeNode *lowestCommonAncestor(TreeNode *head, TreeNode *o1, TreeNode *o2);

// 在二叉树中寻找一个节点的后继节点
PTreeNode *getSuccessorNode(PTreeNode *node);

// 二叉树序列化及反序列化
std::string serialByPre(TreeNode *head);
TreeNode *reconByPreString(std::string preStr);
TreeNode *reconPreOrder(std::queue<std::string> &queue);

// 打印折纸折痕方向(N为折了几次纸条)->二叉树层数(左树是true, 右数是false, 头部为true)
void PrintPaperFolding(int N);
// 以中序遍历的方式打印以当前节点为根节点的整棵树(i为当前节点来到了第几层)
void process_v4(int i, int N, bool down);
#endif