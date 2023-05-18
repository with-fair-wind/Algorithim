#ifndef __TEST_H__
#define __TEST_H__

#include "BinaryTree.h"
#include "Force_Recursion.h"
#include "Graph.h"
#include "Linked_List.h"
#include "Silly_White_Sweet.h"
#include "Sort.h"
#include "Struct.h"
#include "TrieTree_Greedy.h"

const int TESTTIMES = 20000;
const int MAXSIZE = 10;
const int MAXVAL = 100000;

// 常用
void Test_PrintIntBit();

// 概率
void Test_RandomPoolClass();

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
void Test_Morris();

// 贪心算法
void Test_LowestLexicography();
void Test_LessMoneySplitGold();
void Test_GetMedianOfVector();

// 暴力递归
void Test_Hanoi();
void Test_PrintAllSubsquences();
void Test_PrintAllPermutations();
void Test_winScore();
void Test_NQueens();
void Test_RobotWalk();
void Test_coinsMin();
void Test_HorseJump();
void Test_BobDie();

// 常用结构
void Test_KMP();
void Test_Manacher();
void Test_GetMaxWindow();
void Test_GetNearLess();
void Test_MaxTargetA();
void Test_BitCal();
#endif