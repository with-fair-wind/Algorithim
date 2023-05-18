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
//// 方法二
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
int winScoreDP(std::vector<int> &cards);

// N皇后问题
int NQueens_v1(int n);
// [0~i-1]已经确定好了，从第i行开始放，有多少种方法,record前面i-1行的皇后放在哪一列上
int func_v5(std::vector<int> &record, int i, int n);
// 第i行的皇后放到第j行行不行
bool isValid(std::vector<int> &record, int i, int j);
//// 方法二(位运算加速)
int NQueens_v2(int n);
// [0~i-1]已经确定好了，从第i行开始放，有多少种方法
int func_v6(int upperLim, int colLim, int leftDiaLim, int rightDiaLim);

// 机器人达到指定位置方法数
// 假设有排成一行的 N 个位置，记为 1~N，N 一定大于或等于2
// 开始时机器人在其中的 M 位置上(M 一定是 1 ~N 中的一个)，机器人可以往左走或者往右走
// 如果机器人来到 1 位置， 那么下一步只能往右来到 2 位置
// 如果机器人来到 N 位置，那么下一步只能往左来到 N-1 位置
// 规定机器人必须走 K 步，最终能来到 P 位置(P 也一定是 1~N 中的一个)的方法有多少种
int RobotWalk_v1(int N, int M, int P, int K);
int walk(int all, int end, int cur, int step);
int RobotWalk_v2(int N, int M, int P, int K);

// 换钱的最少货币数
// 给定数组 arr，arr 中所有的值都为正数且不重复。
// 每个值代表一种面值的货币，每种面值的货币可以使用任意张
// 再给定一个整数 aim，代表要找的钱数
// 求组成 aim 的最少货币数
int coinsMin_v1(const std::vector<int> &vec, int aim);
int find(const std::vector<int> &vec, int index, int aim);
int coinsMin_v2(const std::vector<int> &vec, int aim);

// 象棋中马的跳法
// 把整个棋盘放入第一象限，棋盘的最左下角是(0, 0)位置,横坐标上9条线、纵坐标上10条线
// 如果“马”从(0,0)位置出发，必须走k步，最后落在(x,y)上的方法数有多少种？
int HorseJump(int x, int y, int k);
int HorseJumpDP(int x, int y, int k);
int getVal(const std::vector<std::vector<std::vector<int>>> &dp, int x, int y, int k);

// Bob的生存概率
// 给定五个参数n,m,i,j,k。表示在一个N*M的区域
// Bob处在(i,j)点，每次Bob等概率的向上、下、左、右四个方向移动一步，Bob必须走K步
// 如果走完之后，Bob还停留在这个区域上，就算Bob存活，否则就算Bob死亡
// 请求解Bob的生存概率，返回字符串表示分数的方式
std::string BobDie(int n, int m, int i, int j, int k);
long liveNum(int n, int m, int i, int j, int k);
// 求两数的最大公约数
inline long gcd(long m, long n) { return n == 0 ? m : gcd(n, m % n); }
std::string BobDieDP(int n, int m, int i, int j, int k);
#endif // __FORCE_RECURSION__