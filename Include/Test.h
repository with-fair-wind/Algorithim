#ifndef __TEST_H__
#define __TEST_H__

#include "BinaryTree.h"
#include "Graph.h"
#include "Linked_List.h"
#include "Silly_White_Sweet.h"
#include "Sort.h"
#include "TrieTree_Greedy.h"

const int TESTTIMES = 10000;
const int MAXSIZE = 100;
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

// 贪心算法
void Test_LowestLexicography();
void Test_LessMoneySplitGold();
void Test_GetMedianOfVector();
#endif