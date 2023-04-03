#ifndef __FUNCTIONAL_H__
#define __FUNCTIONAL_H__

#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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
// RandomPool结构,三个方法都是O(1)的时间复杂度
// insert(key):将某个key加入到该结构，做到不重复加入
// delete(key):将原本在结构中的某个key移除
// getRandom(): 等概率随机返回结构中的任何一个key
template <typename T>
class RandomPool
{
private:
    std::unordered_map<T, int> m_KeyIndexMap;
    std::unordered_map<int, T> m_IndexKeyMap;
    int m_size;
    std::mt19937 m_rng;

public:
    RandomPool() : m_KeyIndexMap(), m_IndexKeyMap(), m_size(0), m_rng(std::time(0)) {}
    void insert_Key(T key)
    {
        if (m_KeyIndexMap.find(key) == m_KeyIndexMap.end())
        {
            m_KeyIndexMap.emplace(key, m_size);
            m_IndexKeyMap.emplace(m_size++, key);
        }
    }

    void delete_Key(T key)
    {
        if (m_KeyIndexMap.find(key) != m_KeyIndexMap.end())
        {
            int DeleteIndex = m_KeyIndexMap[key];
            int lastIndex = --m_size;
            T lastKey = m_IndexKeyMap[lastIndex];

            m_KeyIndexMap[lastKey] = DeleteIndex;
            m_KeyIndexMap.erase(key);
            m_IndexKeyMap[DeleteIndex] = lastKey;
            m_IndexKeyMap.erase(lastIndex);
        }
    }

    T getRandom()
    {
        if (m_size > 0)
        {
            std::uniform_int_distribution<int> u(0, m_size - 1);
            return m_IndexKeyMap[u(m_rng)];
        }
    }
};

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
// 创建随机数组(数组大小、数组元素均随机)进行排序算法
void CreateArrDuiShuQi(int testTimes, int maxSize, int maxValue, void (*pt1)(int *arr, int size), void (*pt2)(int *arr, int size), void (*pt3)(int *arr, int L, int R), void (*pt4)(int *arr, int L, int R));
// 寻找数组中位数
void CreateMedianDuiShuQi(int testTimes, int maxSize, int maxValue, double (*pt1)(std::vector<int> &vec), double (*pt2)(std::vector<int> &vec));
#endif