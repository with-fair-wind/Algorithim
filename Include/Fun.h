#ifndef __FUNCTIONAL_H__
#define __FUNCTIONAL_H__

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <utility>

// uniform_real_distribution用于生成随机浮点数(半闭半开)
// uniform_int_distribution用于生成整数浮点数(闭区间)
// 快慢指针都从头(第一[0])开始时，慢指针最后停在中点位置，对于奇数是刚好中点，对于偶数是向下取整停留，比如6个节点，慢指针会停在第三个节点处而不是第四个节点
// 对于数组也是同样的[L, R]取中点索引L + (R - L / 2),对于奇数是刚好中点，对于偶数是向下取整停留，比如[0, 3]总共四个数会停留在第二个数的位置，也就是索引为1处
const int FIXED_PROBABILITY = 0.84;

/*
***常用功能***
*/
// 打印数组
void printArray(int arr[], int size);
// 基于位运算^的数组元素交换
void swap_bit(int arr[], int i, int j);
// 基于下标的数组元素交换
void swap_arr(int *arr, int i, int j);
// 数组是否有序(从小到大)
bool isSorted(int *arr, int size);

/*
***概率事件***
*/
// L~R范围上等概率返回0和1(R>L)
int ZorOneGetEqualProbability(int L, int R);
// 实现从a~b的等概率随机到c~d的等概率随机
int Range2RangeEqualProbability(int a, int b, int c, int d);
// 0~1(浮点数)范围上不等概率返回0,1，这个概率是内置不可见的(未知)，要求等概率返回0和1
int NoEqual2EqualReturnZorOne();
// 任意x,x属于[0, 1),[0, x)范围上的数出现的概率由x调整为x平方
double xToPower2();

/*
***位运算相关***
*/
// 打印整数32位
void printInteger(int num);
// 一个数组中，只有一种数出现了奇数次，其余数均出现偶数次，找出这个出现了奇数次的数
int Extract1OddNum(int *arr, int size);
// 一个数组中，只有两种数出现了奇数次，其余数均出现偶数次，找出这两个出现了奇数次的数
std::pair<int, int> Extract2OddNum(int *arr, int size);

/*
***二分法相关***
*/
// 找到数组最大值O(N)
int MaxInArr(int *arr, int L, int R);
// 有序数组中找到一个数  二分法O(logN)
bool findNumInSortedArr(int *arr, int num, int L, int R);
// 有序数组中找到一个>=某个数最左边的位置或者<=某个数最右边的位置    二分直到分不下去
int mostLeftNoMoreNumIndex(int *arr, int num, int L, int R);
// 无序且任何相邻两元素均不相等，找到任意一个局部最小的位置  先判断两端，然后必可以二分，然后再二分...
int oneMinIndex(int *arr, int size);

/*
***对数器相关***
*/
// 创建随机数组(数组大小、数组元素均随机)
void CreateArrDuiShuQi(int testTimes, int maxSize, int maxValue, void (*pt1)(int *arr, int size), void (*pt2)(int *arr, int size), void (*pt3)(int *arr, int L, int R), void (*pt4)(int *arr, int L, int R));

#endif