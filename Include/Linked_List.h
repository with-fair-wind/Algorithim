#ifndef __Linked_List_H_
#define __Linked_List_H_

#include "Fun.h"
#include <sstream>
#include <stack>
#include <unordered_map>

struct SingleNode
{
    int value;
    SingleNode *next = nullptr;
    SingleNode(int data = 0, SingleNode *n = nullptr) : value(data), next(n) {}
    ~SingleNode()
    {
        if (next)
        {
            delete next;
            next = nullptr;
        }
    }
};

struct DoubleNode
{
    int value;
    DoubleNode *next = nullptr;
    DoubleNode *last = nullptr;
    DoubleNode(int data = 0, DoubleNode *n = nullptr, DoubleNode *l = nullptr) : value(data), next(n), last(l) {}
    ~DoubleNode()
    {
        if (next)
        {
            delete next;
            next = nullptr;
        }
        if (last)
        {
            delete last;
            last = nullptr;
        }
    }
};

struct RandomNode
{
    int value;
    RandomNode *next = nullptr;
    RandomNode *rand = nullptr;
    RandomNode(int data = 0, RandomNode *n = nullptr, RandomNode *r = nullptr) : value(data), next(n), rand(r) {}
    ~RandomNode()
    {
        if (next)
        {
            delete next;
            next = nullptr;
        }
        if (rand)
        {
            delete rand;
            rand = nullptr;
        }
    }
};

struct RandomNodeHash
{
    std::size_t operator()(const RandomNode *node) const
    {
        return std::hash<int>{}(node->value);
    }
};

struct RandomNodeEqual
{
    bool operator()(const RandomNode *lhs, const RandomNode *rhs) const
    {
        return lhs->value == rhs->value;
    }
};

// 打印单/双链表/乱指针链表
void printSingleLinkedList(SingleNode *sNode);
void printDoubleLinkedList(DoubleNode *dNode);
void printRandLinkedList(RandomNode *rNode);

// 反转单链表
SingleNode *reverseLinkedList(SingleNode *head);

// 反转双链表
// 传进来的head(地址)是拷贝值，函数内head改变了，外界依然指向原head
DoubleNode *reverseDoubleList_v1(DoubleNode *head);
void reverseDoubleList_v2(DoubleNode *head);
// 传进来的head(地址) 是指针，函数内*head改变了，外界地址里的也跟着变
void reverseDoubleList_v3(DoubleNode **head);

// K个节点的组内逆序调整
SingleNode *getGroupEnd(SingleNode *start, int k);
void reverse(SingleNode *start, SingleNode *end);
SingleNode *reverseKGroup(SingleNode *head, int k);

// 两数相加
int ListLength(SingleNode *head);
SingleNode *AddTwoNums(SingleNode *head1, SingleNode *head2);

// 两个有序链表合并
SingleNode *mergeTwoLists(SingleNode *head1, SingleNode *head2);

// 合并K个升序列表
SingleNode *mergeKList(SingleNode *arr[], int K);

// 打印两个有序链表公共的部分
void printCommonPart(SingleNode *head1, SingleNode *head2);

// 判断是否时回文链表
bool isPalindromeList_v1(SingleNode *head);
bool isPalindromeList_v2(SingleNode *head);
bool isPalindromeList_v3(SingleNode *head);

// SmallerEqualBigger
SingleNode *listPartition_v1(SingleNode *head, int pivot);
SingleNode *listPartition_v2(SingleNode *head, int pivot);
void Swap_Node(SingleNode **arr, int i, int j);

// 拷贝一个一模一样的乱指针链表
RandomNode *copyListWithRand_v1(RandomNode *head);
RandomNode *copyListWithRand_v2(RandomNode *head);

SingleNode *getIntersectNode(SingleNode *head1, SingleNode *head2);
SingleNode *getLoopNode(SingleNode *head);
SingleNode *noLoop(SingleNode *head1, SingleNode *head2);
SingleNode *bothLoop(SingleNode *head1, SingleNode *loop1, SingleNode *head2, SingleNode *loop2);
#endif