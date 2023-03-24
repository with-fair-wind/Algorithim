#ifndef __FORCE_RECURSION__H_
#define __FORCE_RECURSION__H_

#include "Fun.h"
#include <stack>

// 汉诺塔问题
void hanoi(int n);
// 打印n层汉诺塔从最左边移动到最右边的全部过程(real代表最底层实际是第几层)
void hanoi(int n, int real, std::string from, std::string help, std::string to);

// 打印一个字符串的全部子序列，包括空字符串
void printAllSubsequence_v2(const std::string &str);
// [0~i-1]已经确定好了，打印包括i索引及后面所有字符的全部子序列(传入参数i最大只能为str.size())
void process(std::vector<char> &chs, size_t i);
// 法二
void printAllSubsquence_v1(std::string str);
void func_v1(std::string str, std::string output);

// 打印一个字符串的全部排列
// 打印一个字符串的全部排列，要求不要出现重复的排列
std::vector<std::string> Permutation(std::string str);
// [0~i-1]已经确定好了，包括i索引及后面所有字符的全排列加入vector返回(传入参数i最大只能为str.size())
void func_v2(std::string str, size_t i, std::vector<std::string> &res);
void swap_str(std::string &str, size_t i, size_t j);

// 逆序一个栈
void reverseStack(std::stack<int> &stack);
int getAndRemoveLastElement(std::stack<int> &stack);

// 规定1和A对应、2和B对应、3和C对应...
// 那么一个数字字符串比如"111"，就可以转化为"AAA"、"KA"和"AK"。
// 给定一个只有数字字符组成的字符串str，返回有多少种转化结果。
int ConvertToLetterString(std::string numStr);
// [0~i-1]已经确定好了，包括i索引及后面所有数字字符共有多少种转化结果(传入参数i最大只能为str.size())
int func_v3(std::string numStr, size_t i);

// 给定两个长度都为N的数组weights和values
// weights[i]和values[i]分别代表i号物品的重量和价值。
// 给定一个正数bag，表示一个载重bag的袋子，你装的物品不能超过这个重量。
// 返回你能装下最多的价值是多少
// (01背包问题)？？？贪心？？
int maxValue(int *weights, int *values, int full, int bag);
// [0~i-1]已经确定好了, 从第i号索引开始想办法装所能得到的最大价值
int func_v4(int *weights, int *values, int full, int bag, int i, int alreadyWeight, int alreadyValues);

// 给定一个整型数组arr，代表数值不同的纸牌排成一条线。
// 玩家A和玩家B依次拿走每张纸牌，规定玩家A先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌
// 玩家A和玩家B都绝顶聪明。(说明先手拿的一定是最佳考虑)请返回最后获胜者的分数。
int winScore(std::vector<int> &cards);
int goFirst(std::vector<int> &cards, int head, int last);
int goLast(std::vector<int> &cards, int head, int last);

#endif // __FORCE_RECURSION__