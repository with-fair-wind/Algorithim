#ifndef __TEST_H__
#define __TEST_H__

#include "BinaryTree.h"
#include "Linked_List.h"
#include "Sort.h"

const int TESTTIMES = 20;
const int MAXSIZE = 10;
const int MAXVAL = 1000;

// 排序(数组)
void Test_SortArr();

// 链表
void Test_SmallerEqualBigger();
void Test_CopyListWithRandom();
void Test_FindFirstIntersectNode();

// 二叉树
void Test_PreInPosTraversal();
void Test_IsBST();
void Test_SerializeAndReconstructTree();
void Test_PrintPaperFolding();
#endif