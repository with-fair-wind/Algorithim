#ifndef __SORT_H_
#define __SORT_H_

#include "Fun.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

void SelectionSort(int arr[], int size); // 选择排序
void BubbleSort(int arr[], int size);    // 冒泡排序
void InsertSort(int arr[], int size);    // 插入排序

// 归并排序
void ProcessSort(int *arr, int L, int R);
void merge_sort(int *arr, int L, int mid, int R);
// 基于归并排序的小和问题
int SmallAdd(int *arr, int L, int R);
int merge_smalladd(int *arr, int L, int mid, int R);
// 基于归并排序的逆对数问题
int InverseLogarithm(int *arr, int L, int R);
int merge_inverselogarithm(int *arr, int L, int mid, int R);

// 荷兰国旗问题1.0(快速排序)
void QuickSort_v1(int *arr, int L, int R);
int patition_v1(int *arr, int L, int R);
// 荷兰国旗问题2.0(快速排序)
void QuickSort_v2(int *arr, int L, int R);
std::pair<int, int> patition_v2(int *arr, int L, int R);

// 堆排序
void heapSort(int *arr, int size);
void heapinsert(int *arr, int index);            // index位置数据能否上移
void heapify(int *arr, int index, int heapsize); // index位置数据能否下移
// 基于堆排序的几乎顺序的数组最大移动范围不超过k的排序
void sortedArrDistanceLessK(int *arr, int size, int k);

// 桶排序
void raidoSort(int *arr, int L, int R);
int maxbits(int *arr, int L, int R);  // 获取数组中最大值元素的十进制位数
int getdigit(int arr_num, int digit); // 取出一个数第digit位上的数字(十进制)   0 -> 个位 ; 1 -> 十位 ...;

#endif