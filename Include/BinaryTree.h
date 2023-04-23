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

// 树形dp
// 二叉树节点间的最大距离问题
// 从二叉树的节点a出发，可以向上或者向下走，但沿途的节点只能经过一次，到达节点b时路
// 径上的节点个数叫作a到b的距离，那么二叉树任何两个节点之间都有距离，求整棵树上的最大距离。
int maxDistance(TreeNode *head);
std::pair<int, int> process_v5(TreeNode *head);

// 派对的最大快乐值
// 员工信息的定义如下 :
struct Employee
{
    int happy;                          // 这名员工可以带来的快乐值
    std::list<Employee *> subordinates; // 这名员工有哪些直接下级
};
// 公司的每个员工都符合 Employee 类的描述。整个公司的人员结构可以看作是一棵标准的、 没有环的多叉树。
// 树的头节点是公司唯一的老板。除老板之外的每个员工都有唯一的直接上级。 叶节点是没有
// 任何下属的基层员工(subordinates列表为空)，除基层员工外，每个员工都有一个或多个直接下级。
// 这个公司现在要办party，你可以决定哪些员工来，哪些员工不来。但是要遵循如下规则。
// 1.如果某个员工来了，那么这个员工的所有直接下级都不能来
// 2.派对的整体快乐值是所有到场员工快乐值的累加
// 3.你的目标是让派对的整体快乐值尽量大
// 给定一棵多叉树的头节点boss，请返回派对的最大快乐值。
int maxHappy(Employee *head);
std::pair<int, int> process_v6(Employee *head);

// Morris遍历
// 一种遍历二叉树的方式，并且时间复杂度O(N)，额外空间复杂度O(1)
// 通过利用原树中大量空闲指针的方式，达到节省空间的目的
void morris(TreeNode *head);
void morrisIn(TreeNode *head);
void morrisPre(TreeNode *head);
void morrisPos(TreeNode *head);
void printInReverse(TreeNode *head);
TreeNode *reserveRightTree(TreeNode *head);
// 应用:判断搜索二叉树
bool isBST_v3(TreeNode *head);
#endif